#include <stdlib.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
  int maxArea = 0;

  int* heights = malloc(matrixColSize[0] * sizeof(int));
  for (int i = 0; i < matrixColSize[0]; ++i) heights[i] = 0;

  int* indices = malloc((matrixColSize[0] + 1) * sizeof(int));

  for (int i = 0; i < matrixSize; ++i) {
    if (matrix[i][0] == '0') {
      heights[0] = 0;
    } else {
      ++heights[0];
    }

    int indicesSize = 0;
    indices[indicesSize++] = 0;

    for (int j = 1; j < matrixColSize[i]; ++j) {
      if (matrix[i][j] == '0') {
        heights[j] = 0;
      } else {
        ++heights[j];
      }

      while (indicesSize != 0 &&
             heights[j] < heights[indices[indicesSize - 1]]) {
        const int idx = indices[--indicesSize];

        const int width =
            indicesSize == 0 ? j : j - indices[indicesSize - 1] - 1;

        const int area = heights[idx] * width;
        if (area > maxArea) maxArea = area;
      }

      indices[indicesSize++] = j;
    }

    while (indicesSize != 0) {
      const int idx = indices[--indicesSize];

      const int width = indicesSize == 0
          ? matrixColSize[i]
          : matrixColSize[i] - indices[indicesSize - 1] - 1;

      const int area = heights[idx] * width;
      if (area > maxArea) maxArea = area;
    }
  }

  free(heights);
  free(indices);

  return maxArea;
}
