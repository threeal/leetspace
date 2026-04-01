static void fill(
    int** image, int imageSize, int* imageColSize, int r, int c,
    int prevColor, int color);

int** floodFill(
    int** image, int imageSize, int* imageColSize, int sr, int sc, int color,
    int* returnSize, int** returnColumnSizes) {
  if (image[sr][sc] != color) {
    fill(image, imageSize, imageColSize, sr, sc, image[sr][sc], color);
  }

  *returnSize = imageSize;
  *returnColumnSizes = imageColSize;
  return image;
}

static void fill(
    int** image, int imageSize, int* imageColSize, int r, int c,
    int prevColor, int color) {
  image[r][c] = color;

  if (r > 0 && image[r - 1][c] == prevColor) {
    fill(image, imageSize, imageColSize, r - 1, c, prevColor, color);
  }

  if (c > 0 && image[r][c - 1] == prevColor) {
    fill(image, imageSize, imageColSize, r, c - 1, prevColor, color);
  }

  if (r + 1 < imageSize && image[r + 1][c] == prevColor) {
    fill(image, imageSize, imageColSize, r + 1, c, prevColor, color);
  }

  if (c + 1 < imageColSize[r] && image[r][c + 1] == prevColor) {
    fill(image, imageSize, imageColSize, r, c + 1, prevColor, color);
  }
}
