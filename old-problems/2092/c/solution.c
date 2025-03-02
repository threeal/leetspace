#include <stdbool.h>
#include <stdlib.h>

static int findRoot(int* roots, int n);

int compare(const void* a, const void* b) {
  return (*(int**)a)[2] - (*(int**)b)[2];
}

int* findAllPeople(
    int n, int** meetings, int meetingsSize, int* meetingsColSize,
    int firstPerson, int* returnSize) {
  (void)meetingsColSize;

  qsort(meetings, meetingsSize, sizeof(int*), compare);

  bool* hasSecrets = malloc(n * sizeof(bool));
  int* roots = malloc(n * sizeof(int));
  int* sizes = malloc(n * sizeof(int));

  for (int i = 0; i < n; ++i) {
    hasSecrets[i] = false;
    roots[i] = i;
    sizes[i] = 1;
  }

  hasSecrets[0] = true;
  hasSecrets[firstPerson] = true;

  int i = 0;
  while (i < meetingsSize) {
    int j = i;
    while (j < meetingsSize && meetings[j][2] == meetings[i][2]) {
      const int a = meetings[j][0], b = meetings[j][1];
      const int rootA = findRoot(roots, a), rootB = findRoot(roots, b);
      if (rootA == rootB) {
        if (hasSecrets[a] || hasSecrets[b]) hasSecrets[rootA] = true;
      } else {
        if (sizes[rootA] >= sizes[rootB]) {
          roots[rootB] = rootA;
          sizes[rootA] += sizes[rootB];
          if (hasSecrets[rootB]) hasSecrets[rootA] = true;
        } else {
          roots[rootA] = rootB;
          sizes[rootB] += sizes[rootA];
          if (hasSecrets[rootA]) hasSecrets[rootB] = true;
        }
      }
      ++j;
    }

    for (int k = i; k < j; ++k) {
      const int a = meetings[k][0], b = meetings[k][1];
      if (hasSecrets[findRoot(roots, a)]) {
        hasSecrets[a] = true;
        hasSecrets[b] = true;
      }
    }

    for (int k = i; k < j; ++k) {
      const int a = meetings[k][0], b = meetings[k][1];
      roots[a] = a;
      roots[b] = b;
      sizes[a] = 1;
      sizes[b] = 1;
    }

    i = j;
  }

  int* output = malloc(n * sizeof(int));
  int outputSize = 0;
  for (int i = 0; i < n; ++i) {
    if (hasSecrets[i]) output[outputSize++] = i;
  }

  free(hasSecrets);
  free(roots);
  free(sizes);

  *returnSize = outputSize;
  return output;
}

static int findRoot(int* roots, int n) {
  return roots[n] == n ? n : (roots[n] = findRoot(roots, roots[n]));
}
