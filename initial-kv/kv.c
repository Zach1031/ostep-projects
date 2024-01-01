#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// using a linked list based on suggestion from original assingment
typedef struct node {
  int key;
  char *val;
  struct node *next;
} node;

void parseLine(const char *line, node *node) {
  node->key = line[0] - '0';
  node->val = malloc(strlen(line) - 1);
  
  char *p1 = node->val;
  const char *p2 = line + 2;

  // assume line ends in new line character
  // final character can be skipped
  while (*(p2 + 1)) {
    *p1++ = *p2++;
  }
}


int main(int argc, char *argv[]) {
  if (argc == 1) {
    exit(0);
  }

  FILE *fp = fopen("d.txt", "r"); 

  node *head = NULL, *curr = NULL, *prev = NULL;
  
  // variables for file read
  size_t read, len;
  char *line = NULL;

  while ((read = getline(&line, &len, fp)) != -1) {
    curr = malloc(sizeof(node));
    parseLine(line, curr);

    if (!head) {
      head = curr;
    }

    else {
      prev->next = curr;
    }

    prev = curr;
  }

  node *test = head;
  while (test) {
    printf("%d -> %s\n", test->key, test->val);
    test = test->next;
  }
}
