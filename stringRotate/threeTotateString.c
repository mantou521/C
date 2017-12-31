#include <stdio.h>
#include "string.h"

void ReverseString(char* s, int from, int to)
{
  while (from < to)
  {
    char t = s[from];
    s[from++] = s[to];
    s[to--] = t;
  }
}

void LeftRotateString(char* s, int n, int m)
{
  m %=n;

  ReverseString(s, 0, m - 1);
  ReverseString(s, m, n - 1);
  ReverseString(s, 0, n - 1);
}

int main() {
  char str[7] = "abcdefg";
  LeftRotateString(str,strlen(str),3);
  printf("%s\n", str);
  return 0;
}
