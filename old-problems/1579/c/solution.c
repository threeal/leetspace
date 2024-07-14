#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct unions_t {
  int components;
  int* parentOf;
};

void unionsInit(struct unions_t* unions, int n) {
  unions->components = n;
  unions->parentOf = malloc((n + 1) * sizeof(int));
  for (int i = n; i >= 0; --i) {
    unions->parentOf[i] = i;
  }
}

void unionsCopy(struct unions_t* dst, const struct unions_t* src, int n) {
  dst->components = src->components;
  dst->parentOf = malloc((n + 1) * sizeof(int));
  memcpy(dst->parentOf, src->parentOf, (n + 1) * sizeof(int));
}

void unionsCleanup(const struct unions_t* unions) {
  free(unions->parentOf);
}

int unionsFindRootOf(struct unions_t* unions, int i) {
  if (unions->parentOf[i] != i)
    unions->parentOf[i] = unionsFindRootOf(unions, unions->parentOf[i]);
  return unions->parentOf[i];
}

bool unionsUnite(struct unions_t* unions, int a, int b) {
  const int rootA = unionsFindRootOf(unions, a);
  const int rootB = unionsFindRootOf(unions, b);
  if (rootA == rootB) return false;
  if (rootA < rootB) {
    unions->parentOf[rootA] = rootB;
  } else {
    unions->parentOf[rootB] = rootA;
  }
  --unions->components;
  return true;
}

bool unionsIsAllConnected(struct unions_t* unions) {
  return unions->components == 1;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
  (void)edgesColSize;

  int requiredEdges = 0;

  struct unions_t alice;
  unionsInit(&alice, n);

  for (int i = edgesSize - 1; i >= 0; --i) {
    if (edges[i][0] == 3 && unionsUnite(&alice, edges[i][1], edges[i][2])) {
      ++requiredEdges;
    }
  }

  struct unions_t bob;
  unionsCopy(&bob, &alice, n);

  for (int i = edgesSize - 1; i >= 0; --i) {
    switch (edges[i][0]) {
      case 1:
        if (unionsUnite(&alice, edges[i][1], edges[i][2])) ++requiredEdges;
        break;

      case 2:
        if (unionsUnite(&bob, edges[i][1], edges[i][2])) ++requiredEdges;
        break;
    }
  }

  const int output = unionsIsAllConnected(&alice) && unionsIsAllConnected(&bob)
      ? edgesSize - requiredEdges
      : -1;

  unionsCleanup(&alice);
  unionsCleanup(&bob);

  return output;
}
