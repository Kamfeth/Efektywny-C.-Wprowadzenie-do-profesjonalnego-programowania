#include <stdio.h>

void retrieve(const int counter) {
  printf("%d ", counter);
}
void increment(void) {
  static unsigned int counter = 0;
  retrieve(counter);
  counter++;
  printf("%d ", counter);
}
int main(void) {
  for (int i = 0; i < 5; i++) {
    increment();
  }
  return 0;
}