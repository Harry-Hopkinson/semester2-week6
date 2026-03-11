#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("%s filename\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  int lines = 0, words = 0, characters = 0;
  char c;

  while ((c = fgetc(file)) != EOF)
  {
    characters++;
    if (c == '\n')
      lines++;
    if (c == ' ' || c == '\n' || c == '\t')
      words++;
  }

  if (characters > 0 && (c != ' ' && c != '\n' && c != '\t'))
    words++;

  fclose(file);

  printf("Lines: %d\n", lines);
  printf("Words: %d\n", words);
  printf("Characters: %d\n", characters);

  return 0;
}