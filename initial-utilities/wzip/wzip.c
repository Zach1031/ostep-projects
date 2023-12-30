#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  
  char curr = -1, last = 0; 
  int first = 1, count = 0;
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (!fp) {
      printf("wzip: cannot open file\n");
      exit(1);
    }

    curr = fgetc(fp);

    while (curr != EOF) {
      if (first) {
        first = 0;
      }

      else {
        if (curr != last) {
          fwrite(&count, 4, 1, stdout);
          fwrite(&last, 1, 1, stdout);

          count = 0;
        }
      }

      last = curr;
      curr = fgetc(fp);
      count++;
    }

    fclose(fp);
  }

  fwrite(&count, 4, 1, stdout);
  fwrite(&last, 1, 1, stdout);

  exit(0);
}
