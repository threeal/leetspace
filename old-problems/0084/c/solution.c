int largestRectangleArea(int* heights, int heightsSize) {
  int indices[100000];
  int indicesTop = -1;

  int lefts[100000];
  for (int i = 0; i < heightsSize; ++i) {
    while (indicesTop >= 0 && heights[indices[indicesTop]] >= heights[i]) {
      --indicesTop;
    }

    lefts[i] = indicesTop < 0 ? 0 : indices[indicesTop] + 1;
    indices[++indicesTop] = i;
  }

  indicesTop = -1;
  int rights[100000];
  for (int i = heightsSize - 1; i >= 0; --i) {
    while (indicesTop >= 0 && heights[indices[indicesTop]] >= heights[i]) {
      --indicesTop;
    }

    rights[i] = indicesTop < 0 ? heightsSize - 1 : indices[indicesTop] - 1;
    indices[++indicesTop] = i;
  }

  int largestArea = 0;
  for (int i = 0; i < heightsSize; ++i) {
    const int area = heights[i] * (rights[i] - lefts[i] + 1);
    if (area > largestArea) largestArea = area;
  }

  return largestArea;
}
