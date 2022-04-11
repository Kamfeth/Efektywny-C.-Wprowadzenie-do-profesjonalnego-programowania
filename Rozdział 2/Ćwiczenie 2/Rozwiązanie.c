#include <ctype.h>
#include <stdio.h>

int main(void)
{
  const int (*functions[3])(const int character) = {isalpha, isupper, islower};
  printf("%s", functions[1]('K') ? "true" : "false");
}