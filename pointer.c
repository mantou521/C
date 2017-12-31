#include <stdio.h>

int main()
{
  int var = 20;
  int *ip;

  ip = &var;

  printf("Address of var variable: %p\n", &var);

  printf("%p\n", ip);

  printf("%d\n", *ip);
}
