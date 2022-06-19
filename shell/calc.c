#include "shell.h"
#include <stdio.h>
#include <math.h>

void calc(char *value1, char *op, char *value2)
{
  float n1 = atof(value1);
  float n2 = atof(value2);

  if (strcmp(op, "+") == 0)
  {
    printf("%.3f\n", n1 + n2);
  }
  else if (strcmp(op, "-") == 0)
  {
    printf("%f\n", n1 - n2);
  }
  else if (strcmp(op, "*") == 0)
  {
    printf("%.3f\n", n1 * n2);
  }
  else if (strcmp(op, "/") == 0)
  {
    if (n2 == 0)
      printf("Division by 0!\n");
    else
      printf("%.3f\n", n1 / n2);
  }
  else if (strcmp(op, "^") == 0)
  {
    printf("%.3f\n", powf(n1, n2));
  }
}

void bits(char *op1, char *op, char *op2)
{
  int n1 = atoi(op1);
  int n2 = atoi(op2);

  if (strcmp(op, "&") == 0)
  {
    printf("%d\n", n1 & n2);
  }
  else if (strcmp(op, "^") == 0)
  {
    printf("%d\n", n1 ^ n2);
  }
  else if (strcmp(op, "|") == 0)
  {
    printf("%d\n", n1 | n2);
  }
}
