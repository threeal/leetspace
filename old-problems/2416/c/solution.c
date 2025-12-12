#include <stdlib.h>

struct node_t {
  int count;
  struct node_t* nexts[26];
};

struct node_t* allocNode(void) {
  struct node_t* node = malloc(sizeof(struct node_t));
  node->count = 1;
  for (int i = 0; i < 26; ++i) node->nexts[i] = NULL;
  return node;
}

void freeNode(struct node_t* node) {
  for (int i = 0; i < 26; ++i) {
    if (node->nexts[i] != NULL) freeNode(node->nexts[i]);
  }
  free(node);
}

int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
  struct node_t* root = allocNode();

  for (int i = 0; i < wordsSize; ++i) {
    struct node_t* node = root;
    for (char* c = words[i]; *c != 0; ++c) {
      struct node_t** next = node->nexts + *c - 'a';
      if (*next == NULL) {
        *next = allocNode();
      } else {
        ++((*next)->count);
      }
      node = *next;
    }
  }

  int* output = malloc(wordsSize * sizeof(int));
  for (int i = 0; i < wordsSize; ++i) {
    int total = 0;
    struct node_t* node = root;
    for (char* c = words[i]; *c != 0; ++c) {
      struct node_t** next = node->nexts + *c - 'a';
      total += (*next)->count;
      node = *next;
    }
    output[i] = total;
  }

  freeNode(root);

  *returnSize = wordsSize;
  return output;
}
