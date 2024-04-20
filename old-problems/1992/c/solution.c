#include <stdlib.h>

struct coordinates_node_t {
  int* data;
  struct coordinates_node_t* next;
};

int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;

  struct coordinates_node_t* coordinates_begin = malloc(sizeof(struct coordinates_node_t));
  struct coordinates_node_t* coordinates = coordinates_begin;
  coordinates->data = NULL;
  coordinates->next = NULL;

  for (int y1 = 0; y1 < landSize; ++y1) {
    for (int x1 = 0; x1 < landColSize[y1]; ++x1) {
      if (land[y1][x1] != 1) continue;

      // Search for the bottom limit.
      int y2 = y1 + 1;
      while (y2 < landSize) {
        if (land[y2][x1] != 1) break;
        ++y2;
      }

      // Search for the right limit.
      int x2 = x1 + 1;
      while (x2 < landColSize[y1]) {
        if (land[y1][x2] != 1) break;
        ++x2;
      }

      ++(*returnSize);

      coordinates->data = malloc(sizeof(int) * 4);
      coordinates->data[0] = y1;
      coordinates->data[1] = x1;
      coordinates->data[2] = y2 - 1;
      coordinates->data[3] = x2 - 1;

      coordinates->next = malloc(sizeof(struct coordinates_node_t));
      coordinates = coordinates->next;
      coordinates->data = NULL;
      coordinates->next = NULL;

      // Clear the farmland, preventing it from being counted twice.
      for (int y = y1; y < y2; ++y) {
        for (int x = x1; x < x2; ++x) {
          land[y][x] = 0;
        }
      }
    }
  }

  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  int** returnData = malloc(*returnSize * sizeof(int*));

  coordinates = coordinates_begin;
  for (int i = 0; i < *returnSize; ++i) {
    (*returnColumnSizes)[i] = 4;
    returnData[i] = coordinates->data;
    coordinates = coordinates->next;
  }

  return returnData;
}
