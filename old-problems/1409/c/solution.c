#include <stdlib.h>

static void update(int* tree, int treeSize, int i, int delta);
static int query(int* tree, int i);

int* processQueries(int* queries, int queriesSize, int m, int* returnSize) {
  const int treeSize = queriesSize + m + 1;
  int* tree = malloc(treeSize * sizeof(int));
  for (int i = 0; i < treeSize; ++i) tree[i] = 0;

  int* map = malloc((m + 1) * sizeof(int));

  for (int i = 1; i <= m; ++i) {
    update(tree, treeSize, queriesSize + i, 1);
    map[i] = queriesSize + i;
  }

  int* output = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    output[i] = query(tree, map[queries[i]] - 1);
    update(tree, treeSize, map[queries[i]], -1);
    update(tree, treeSize, queriesSize - i, 1);
    map[queries[i]] = queriesSize - i;
  }

  free(tree);
  free(map);

  *returnSize = queriesSize;
  return output;
}

static void update(int* tree, int treeSize, int i, int delta) {
  const int n = treeSize;
  while (i < n) {
    tree[i] += delta;
    i += i & -i;
  }
}

static int query(int* tree, int i) {
  int sum = 0;
  while (i > 0) {
    sum += tree[i];
    i -= i & -i;
  }
  return sum;
}
