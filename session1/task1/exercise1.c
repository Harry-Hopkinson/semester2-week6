#include <stdio.h>

int get_input(const char *prompt)
{
  char input[64];
  int value = 0;

  printf("%s", prompt);
  if (fgets(input, sizeof(input), stdin))
  {
    sscanf(input, "%d", &value);
  }

  return value;
}

int calculate_fine(int speed_limit, int driver_speed)
{
  if (driver_speed <= speed_limit) return 0;

  int excess = driver_speed - speed_limit;
  if (excess <= 10) return 50;
  else if (excess <= 20) return 100;
  else return 200;
}

void print_fine(int fine)
{
  if (fine > 0) printf("Fine: $%d\n", fine);
  else printf("No fine needed.\n");
}

int main(void)
{
  int speed_limit = get_input("Enter the speed limit: ");
  int driver_speed = get_input("Enter the driver's speed: ");

  int fine = calculate_fine(speed_limit, driver_speed);
  print_fine(fine);

  return 0;
}