static int explore(int** mat, int matSize, int* matColSize, int i, int j);

int minFlips(int** mat, int matSize, int* matColSize) {
  const int flips = explore(mat, matSize, matColSize, 0, 0);
  return flips < 1000 ? flips : -1;
}

static int explore(int** mat, int matSize, int* matColSize, int i, int j) {
  if (i == matSize) {
    for (int i = 0; i < matSize; ++i) {
      for (int j = 0; j < matColSize[i]; ++j) {
        if (mat[i][j] == 1) return 1000;
      }
    }
    return 0;
  } else if (j == matColSize[i]) {
    return explore(mat, matSize, matColSize, i + 1, 0);
  } else {
    const int noFlip = explore(mat, matSize, matColSize, i, j + 1);

    mat[i][j] = mat[i][j] == 0 ? 1 : 0;
    if (i > 0) mat[i - 1][j] = mat[i - 1][j] == 0 ? 1 : 0;
    if (i + 1 < matSize) mat[i + 1][j] = mat[i + 1][j] == 0 ? 1 : 0;
    if (j > 0) mat[i][j - 1] = mat[i][j - 1] == 0 ? 1 : 0;
    if (j + 1 < matColSize[i]) mat[i][j + 1] = mat[i][j + 1] == 0 ? 1 : 0;

    const int withFlip = 1 + explore(mat, matSize, matColSize, i, j + 1);

    mat[i][j] = mat[i][j] == 0 ? 1 : 0;
    if (i > 0) mat[i - 1][j] = mat[i - 1][j] == 0 ? 1 : 0;
    if (i + 1 < matSize) mat[i + 1][j] = mat[i + 1][j] == 0 ? 1 : 0;
    if (j > 0) mat[i][j - 1] = mat[i][j - 1] == 0 ? 1 : 0;
    if (j + 1 < matColSize[i]) mat[i][j + 1] = mat[i][j + 1] == 0 ? 1 : 0;

    return noFlip < withFlip ? noFlip : withFlip;
  }
}
