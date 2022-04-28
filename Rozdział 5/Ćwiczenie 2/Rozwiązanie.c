#include <stdio.h>

size_t find_element(size_t len, int arr[len], int key) {
  size_t pos = (size_t)-1;
  // przechodzenie w obrębie tablicy i wyszukiwanie klucza
  for (size_t i = 0; i < len; ++i) {
    if (arr[i] == key) {
      pos = i;
      break; // zakończenie działania pętli
    }
  }
  return pos;
}

int main(void) {
  int numbers[] = {2, 3, 5, 7, 11};
  if (find_element(5, numbers, 7) == -1) {
    printf("Nie udało się odnaleźć klucza wśród elementów tablicy");
  }
}