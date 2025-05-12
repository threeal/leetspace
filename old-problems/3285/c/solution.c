int* stableMountains(
    int* height, int heightSize, int threshold, int* returnSize) {
  --heightSize;
  int n = 0;
  for (int i = 0; i < heightSize; ++i) {
    if (height[i] > threshold) height[n++] = i + 1;
  }
  *returnSize = n;
  return height;
}
