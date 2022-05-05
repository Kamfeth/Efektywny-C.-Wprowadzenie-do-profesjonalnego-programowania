#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int closedir(DIR *dirp) {
  free(dirp->d_buf);
  return close(dirp->d_fd); // obszar pamięci wskazywany przez dirp został już zwolniony
}

int main(void) {
  DIR *directory = opendir("C:\\Windows");
  closedir(directory);
  free(directory);
}

/* Powyższy kod jest rozwiązaniem teoretycznym. Czytając zawartość nagłówka dirent.h, nie byłem w stanie odnaleźć pól d_buf oraz
   d_fd dla wskaźnika DIR. Dowiedziałem się, że podobno nagłówek dirent.h może mieć subtelnie odmienną implementację, ponieważ nie
   jest on oficjalną częścią standardu języka C. Dlatego też napisałem rozwiązanie, które zakłada, że pola d_buf oraz d_fd obiektu
   DIR rzeczywiście znajdują się w pliku nagłówkowym dirent.h */