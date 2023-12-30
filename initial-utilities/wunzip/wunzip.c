#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (!fp) {
      printf("wunzip: cannot open file\n");
      exit(1);
    }

    int count;
    char c;

    while (fread(&count, 4, 1, fp)) {
      fread(&c, 1, 1, fp);

      while (count--) {
        printf("%c", c);
      }
    }

    fclose(fp);
  }
}
