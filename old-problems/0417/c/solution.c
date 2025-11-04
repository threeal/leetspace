#include <stdlib.h>

static void explorePacific(
    int** heights, char** flags, int h, int w, int y, int x);

static void exploreAtlantic(
    int*** output, int** outputColSizes, int* outputSize,
    int** heights, char** flags, int h, int w, int y, int x);

int** pacificAtlantic(
    int** heights, int heightsSize, int* heightsColSize,
    int* returnSize, int** returnColumnSizes) {
  const int h = heightsSize;
  const int w = heightsColSize[0];

  char** flags = malloc(h * sizeof(char*));
  for (int y = 0; y < h; ++y) {
    flags[y] = malloc(w * sizeof(char));
    for (int x = 0; x < w; ++x) flags[y][x] = 0;
  }

  for (int y = 0; y < h; ++y) {
    if (flags[y][0] == 0) explorePacific(heights, flags, h, w, y, 0);
  }

  for (int x = 0; x < w; ++x) {
    if (flags[0][x] == 0) explorePacific(heights, flags, h, w, 0, x);
  }

  int** output = malloc(w * h * sizeof(int*));
  int* outputColSizes = malloc(w * h * sizeof(int));
  int outputSize = 0;

  for (int y = 0; y < h; ++y) {
    if (flags[y][w - 1] < 2) {
      exploreAtlantic(
          &output, &outputColSizes, &outputSize,
          heights, flags, h, w, y, w - 1);
    }
  }

  for (int x = 0; x < w; ++x) {
    if (flags[h - 1][x] < 2) {
      exploreAtlantic(
          &output, &outputColSizes, &outputSize,
          heights, flags, h, w, h - 1, x);
    }
  }

  for (int y = 0; y < h; ++y) free(flags[y]);
  free(flags);

  *returnSize = outputSize;
  *returnColumnSizes = outputColSizes;
  return output;
}

static void explorePacific(
    int** heights, char** flags, int h, int w, int y, int x) {
  flags[y][x] = 1;

  if (y > 0 && flags[y - 1][x] == 0 && heights[y - 1][x] >= heights[y][x]) {
    explorePacific(heights, flags, h, w, y - 1, x);
  }

  if (x > 0 && flags[y][x - 1] == 0 && heights[y][x - 1] >= heights[y][x]) {
    explorePacific(heights, flags, h, w, y, x - 1);
  }

  if (y + 1 < h && flags[y + 1][x] == 0 &&
      heights[y + 1][x] >= heights[y][x]) {
    explorePacific(heights, flags, h, w, y + 1, x);
  }

  if (x + 1 < w && flags[y][x + 1] == 0 &&
      heights[y][x + 1] >= heights[y][x]) {
    explorePacific(heights, flags, h, w, y, x + 1);
  }
}

static void exploreAtlantic(
    int*** output, int** outputColSizes, int* outputSize,
    int** heights, char** flags, int h, int w, int y, int x) {
  if ((flags[y][x] |= 2) == 3) {
    int* arr = malloc(2 * sizeof(int));
    arr[0] = y;
    arr[1] = x;

    (*output)[*outputSize] = arr;
    (*outputColSizes)[*outputSize] = 2;
    ++(*outputSize);
  }

  if (y > 0 && flags[y - 1][x] < 2 && heights[y - 1][x] >= heights[y][x]) {
    exploreAtlantic(
        output, outputColSizes, outputSize, heights, flags, h, w, y - 1, x);
  }

  if (x > 0 && flags[y][x - 1] < 2 && heights[y][x - 1] >= heights[y][x]) {
    exploreAtlantic(
        output, outputColSizes, outputSize, heights, flags, h, w, y, x - 1);
  }

  if (y + 1 < h && flags[y + 1][x] < 2 &&
      heights[y + 1][x] >= heights[y][x]) {
    exploreAtlantic(
        output, outputColSizes, outputSize, heights, flags, h, w, y + 1, x);
  }

  if (x + 1 < w && flags[y][x + 1] < 2 &&
      heights[y][x + 1] >= heights[y][x]) {
    exploreAtlantic(
        output, outputColSizes, outputSize, heights, flags, h, w, y, x + 1);
  }
}
