#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct list_node_t {
  int value;
  struct list_node_t* next;
};

int exploreBob(
    struct list_node_t** neighbors, int* amount, int prev, int node, int depth);

int exploreAlice(
    struct list_node_t** neighbors, int* amount, int prev, int node);

int mostProfitablePath(
    int** edges, int edgesSize, int* edgesColSize,
    int bob, int* amount, int amountSize) {
  (void)edgesColSize;

  struct list_node_t** neighbors =
      malloc(amountSize * sizeof(struct list_node_t*));
  memset(neighbors, 0, amountSize * sizeof(struct list_node_t*));

  for (int i = edgesSize - 1; i >= 0; --i) {
    struct list_node_t* node = malloc(sizeof(struct list_node_t));
    node->value = edges[i][1];
    node->next = neighbors[edges[i][0]];
    neighbors[edges[i][0]] = node;

    node = malloc(sizeof(struct list_node_t));
    node->value = edges[i][0];
    node->next = neighbors[edges[i][1]];
    neighbors[edges[i][1]] = node;
  }

  exploreBob(neighbors, amount, -1, bob, 0);
  const int profit = exploreAlice(neighbors, amount, -1, 0);

  for (int i = edgesSize - 1; i >= 0; --i) {
    struct list_node_t* node = neighbors[i];
    while (node != NULL) {
      struct list_node_t* temp = node->next;
      free(node);
      node = temp;
    }
  }
  free(neighbors);

  return profit;
}

int exploreBob(
    struct list_node_t** neighbors, int* amount,
    int prev, int node, int depth) {
  for (struct list_node_t* child = neighbors[node];
       child != NULL; child = child->next) {
    if (child->value == prev) continue;
    const int zeroDepth = child->value != 0
        ? exploreBob(neighbors, amount, node, child->value, depth + 1)
        : 1;

    if (zeroDepth >= 0) {
      if (depth < zeroDepth) {
        amount[node] = 0;
      } else if (depth == zeroDepth) {
        amount[node] /= 2;
      }
      return 1 + zeroDepth;
    }
  }

  return -1;
}

int exploreAlice(
    struct list_node_t** neighbors, int* amount, int prev, int node) {
  int maxProfit = INT_MIN;
  for (struct list_node_t* child = neighbors[node];
       child != NULL; child = child->next) {
    if (child->value == prev) continue;
    const int profit = exploreAlice(neighbors, amount, node, child->value);
    if (profit > maxProfit) maxProfit = profit;
  }

  if (maxProfit == INT_MIN) maxProfit = 0;
  return amount[node] + maxProfit;
}
