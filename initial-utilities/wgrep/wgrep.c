#include <stdio.h>
#include <stdlib.h>

int hasNeedle(const char *hay, const char *needle) {
  while (*hay) {
    if (*hay == *needle) {
      const char *p1 = hay;
      const char *p2 = needle;

      int found = 1;
      while (*p1 && *p2) {
        if (*p1++ != *p2++) {
          found = 0;
          break;
        }
      }

      if (found) {
        return 1;
      }
    }

    hay++;
  }

  return 0;
}

void searchForTerm(FILE *fp, char *needle) {
  if (!fp) {
    printf("wgrep: cannot open file\n");
    exit(1);
  }

  char *line = NULL; 
  size_t lineSize;
  int read;


  while ((read = getline(&line, &lineSize, fp)) != -1) {
    if (hasNeedle(line, needle)) {
      printf("%s", line);
    }
  }
}

int main(int argc, char *argv[]) {
  // too many or too few command line args
  if (argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  
  char *needle = argv[1];
  if (argc == 2) {
    searchForTerm(stdin, needle);
  }

  else {
    for (int i = 2; i < argc; i++) {
      searchForTerm(fopen(argv[i], "r"), needle);
    }
  }
}
