#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n)
{
  // the base case - this determines when the recursion should stop
  if (n == 0) return 1;

  return n * factorial(n - 1);
}

int main(int argc, char **argv)
{
  /*
  The program should accept a command line argument as follows:
  ./combinatorials n C r
  ./combinatorials n P r

  where n and r are both positive integers, and r is always less than or equal to n.

  for example:
  ./combinatorials 7 C 2

  Your program should then calculate and print out the correct result

  nCr should return the total combinations of r items out of n.
  This is calculated by: n! / (r! (n - r)!)

  nPr should return the total permutations of r items out of n.
  This is calculated by: n! / (n-r)!

  Add appropriate validation to your program to make your code robust.

  You should try and use functions to write your program.

  */

  if (argc < 3)
  {
    printf("Usage:\n");
    printf("%s n C/P r\n", argv[0]);
    return 1;
  }

  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[3]);
  char *operation = argv[2];

  if (num1 < 0 || num2 < 0)
  {
    printf("n and r must be positive integers.\n");
    return 1;
  }

  if (num2 > num1)
  {
    printf("r must be less than or equal to n.\n");
    return 1;
  }

  // n! / (r! (n - r)!)
  if (strcmp(operation, "C") == 0)
  {
    int result = factorial(num1) / (factorial(num2) * factorial(num1 - num2));
    printf("%d C %d = %d\n", num1, num2, result);
  }
  // n! / (n-r)!
  else if (strcmp(operation, "P") == 0)
  {
    int result = factorial(num1) / factorial(num1 - num2);
    printf("%d P %d = %d\n", num1, num2, result);
  }
  else
  {
    printf("Unknown operation '%s'. Use C for combinations or P for permutations.\n", operation);
    return 1;
  }
}