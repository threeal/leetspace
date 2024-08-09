#include <stdlib.h>

int minHeightShelves(
    int** books, int booksSize, int* booksColSize, int shelfWidth) {
  (void)booksColSize;

  int* minHeights = malloc((booksSize + 1) * sizeof(int));
  minHeights[booksSize] = 0;

  for (int i = booksSize - 1; i >= 0; --i) {
    int width = books[i][0];
    int height = books[i][1];

    minHeights[i] = height + minHeights[i + 1];
    for (int j = i + 1; j < booksSize; ++j) {
      width += books[j][0];
      if (width > shelfWidth) break;
      if (books[j][1] > height) height = books[j][1];
      if (height + minHeights[j + 1] < minHeights[i]) {
        minHeights[i] = height + minHeights[j + 1];
      }
    }
  }

  return minHeights[0];
}
