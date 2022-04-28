#include <stdio.h>

long long absolute_value(long long a) {
  if (a < 0) {
    return -a;
  }
  return a;
}

int main(void) {
  printf("%lld", absolute_value(-1125899906842624));
}