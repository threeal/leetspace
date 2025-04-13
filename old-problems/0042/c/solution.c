int trap(int* height, int heightSize) {
  int volume = 0, l = 0, r = heightSize - 1;
  while (l + 1 < r) {
    if (height[l] <= height[r]) {
      if (height[l] > height[l + 1]) {
        volume += height[l] - height[l + 1];
        height[l + 1] = height[l];
      }
      ++l;
    } else {
      if (height[r] > height[r - 1]) {
        volume += height[r] - height[r - 1];
        height[r - 1] = height[r];
      }
      --r;
    }
  }
  return volume;
}
