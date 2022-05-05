#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DMALLOC
#include "dmalloc.h"
#endif

void usage(char *msg) {
  fprintf(stderr, "%s", msg);
  free(msg);
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 4) {
    /* Komunikat o błędzie nie będzie liczyć więcej niż 80 znaków */
    char *errmsg = (char *)malloc(80);
    sprintf(
      errmsg,
      "Przepraszamy %s,\nUżycie: caesar plik_hasła plik_kluczy [plik_wyjściowy]\n",
      getenv("USER")
    );
    usage(errmsg);
    free(errmsg);
    exit(EXIT_FAILURE);
  }

  // ---fragment kodu---
  exit(EXIT_SUCCESS);
}

/* Przy użyciu biblioteki Dmalloc w wersji 5.6.5 udało się dokonać dodatkowe sprawdzenia powyższego programu. Zastosowano różne
   kombinacje danych wejściowych, aby zidentyfikować inne błędy związane z zarządzaniem pamięci. */