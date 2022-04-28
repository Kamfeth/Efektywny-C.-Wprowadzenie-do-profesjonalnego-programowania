#include <stdio.h>
#include <stdlib.h>

int do_something(void) {
  FILE *file1, *file2;
  typedef int object_t;
  object_t *obj;
  int ret_val = 0; // Przyjęcie początkowego pomyślnego uzyskania wartości zwracanej

  file1 = fopen("a_file", "w");
  if (file1 == NULL) {
    ret_val = -1;
    goto FAIL_FILE1;
  }

  file2 = fopen("another_file", "w");
  if (file2 == NULL) {
    ret_val = -2;
    goto FAIL_FILE2;
  }

  obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    ret_val = -3;
    goto FAIL_OBJ;
  }
  // Działanie dotyczące alokowanych zasobów

  //Czyszczenie wszystkiego
  free(obj);
FAIL_OBJ: // W przeciwnym razie zamknięcie tylko otwartych zasobów
  fclose(file2);
FAIL_FILE2:
  fclose(file1);
FAIL_FILE1:
  return ret_val;
}

int main(void) {
  switch (do_something()) {
    case 0:
      printf("Funkcja zadziałała prawidłowo!");
      break;
    case -1:
      printf("Nie udało się otworzyć pliku a_file");
      break;
    case -2:
      printf("Nie udało się otworzyć pliku another_file");
      break;
    case -3:
      printf("Nie udało się przydzielić pamięci do zmiennej typu object_t");
      break;
  }
}