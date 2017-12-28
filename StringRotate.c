#include "string.h"
#include <stdio.h>
void LeftShiftOne(char* s, int n)
{
    char t = s[0];  //保存第一个字符
    for (int i = 1; i < n; i++)
    {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}

void LeftRotateString(char* s, int n, int m)
{
    while (m--)
    {
        LeftShiftOne(s, n);
    }
}
int main() {
  char str[7] = "abcdefg";
  LeftRotateString(str,strlen(str),3);
  printf("%s\n", str);
  return 0;
}
