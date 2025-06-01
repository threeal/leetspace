#include <stdlib.h>
#include <string.h>

static int nodes[16];
static int nodesSize = 0;

static int** output = NULL;
static int outputSize = 0;
static int outputMaxSize = 0;
static int* outputColSize = NULL;
static int* outputMaxColSize = NULL;

static void backtrack(int** graph, int* graphColSize, int node, const int n);

int** allPathsSourceTarget(
    int** graph, int graphSize, int* graphColSize,
    int* returnSize, int** returnColumnSizes) {
  nodesSize = 0;
  outputSize = 0;
  backtrack(graph, graphColSize, 0, graphSize - 1);
  *returnSize = outputSize;
  *returnColumnSizes = outputColSize;
  return output;
}

static void backtrack(int** graph, int* graphColSize, int node, const int n) {
  nodes[nodesSize++] = node;
  if (node == n) {
    if (outputSize == outputMaxSize) {
      if (outputMaxSize == 0) {
        outputMaxSize = 32;
        output = malloc(outputMaxSize * sizeof(int*));
        outputColSize = malloc(outputMaxSize * sizeof(int));
        outputMaxColSize = malloc(outputMaxSize * sizeof(int));
        for (int i = 0; i < outputMaxSize; ++i) outputMaxColSize[i] = 0;
      } else {
        outputMaxSize *= 32;
        output = realloc(output, outputMaxSize * sizeof(int*));
        outputColSize = realloc(outputColSize, outputMaxSize * sizeof(int));
        outputMaxColSize = realloc(
            outputMaxColSize, outputMaxSize * sizeof(int));
        for (int i = outputMaxSize / 32; i < outputMaxSize; ++i) {
          outputMaxColSize[i] = 0;
        }
      }
    }
    if (nodesSize > outputMaxColSize[outputSize]) {
      output[outputSize] = outputMaxColSize[outputSize] == 0
          ? malloc(nodesSize * sizeof(int))
          : realloc(output[outputSize], nodesSize * sizeof(int));
      outputMaxColSize[outputSize] = nodesSize;
    }
    memcpy(output[outputSize], nodes, nodesSize * sizeof(int));
    outputColSize[outputSize++] = nodesSize;
  } else {
    for (int i = 0; i < graphColSize[node]; ++i) {
      backtrack(graph, graphColSize, graph[node][i], n);
    }
  }
  --nodesSize;
}
