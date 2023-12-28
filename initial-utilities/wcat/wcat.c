#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    exit(0);
  }

  FILE *fp;
  for (int i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (!fp) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    char c;
    while ((c = fgetc(fp)) != EOF) {
      printf("%c", c);
    }
  

    fclose(fp);
  }
  exit(0);
}
