#include <stdlib.h>
#include <string.h>

struct node_t {
  int val;
  struct node_t* next;
};

int splitOrMerge(
    struct node_t** leaves, int* values, int k, int parent, int node);

int maxKDivisibleComponents(
    int n, int** edges, int edgesSize, int* edgesColSize,
    int* values, int valuesSize, int k) {
  (void)edgesColSize;
  (void)valuesSize;

  struct node_t** leaves = malloc(n * sizeof(struct node_t*));
  for (int i = 0; i < n; ++i) leaves[i] = NULL;

  for (int i = 0; i < edgesSize; ++i) {
    struct node_t* leaf = malloc(sizeof(struct node_t));
    leaf->val = edges[i][1];
    leaf->next = leaves[edges[i][0]];
    leaves[edges[i][0]] = leaf;

    leaf = malloc(sizeof(struct node_t));
    leaf->val = edges[i][0];
    leaf->next = leaves[edges[i][1]];
    leaves[edges[i][1]] = leaf;
  }

  return splitOrMerge(leaves, values, k, -1, 0);
}

int splitOrMerge(
    struct node_t** leaves, int* values, int k, int parent, int node) {
  int count = 0;

  for (struct node_t* leaf = leaves[node]; leaf != NULL; leaf = leaf->next) {
    if (leaf->val == parent) continue;
    count += splitOrMerge(leaves, values, k, node, leaf->val);
  }

  if (values[node] % k == 0) {
    ++count;
  } else if (parent >= 0) {
    values[parent] = (values[parent] + values[node]) % k;
  }

  return count;
}
