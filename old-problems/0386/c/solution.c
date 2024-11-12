#include <stdlib.h>

static void pushLexicalOrder(int** it, int num, int n);

int* lexicalOrder(int n, int* returnSize) {
  int* out = malloc(n * sizeof(int));
  *returnSize = n;

  int* it = out;
  const int end = n < 9 ? n : 9;
  for (int i = 1; i <= end; ++i) {
    pushLexicalOrder(&it, i, n);
  }

  return out;
}

static void pushLexicalOrder(int** it, int num, int n) {
  **it = num;
  ++(*it);
  if (num * 10 <= n) {
    const int end = n < num * 10 + 9 ? n : num * 10 + 9;
    for (int i = num * 10; i <= end; ++i) {
      pushLexicalOrder(it, i, n);
    }
  }
}
