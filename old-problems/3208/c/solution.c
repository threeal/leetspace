int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
  int count = 0, l = 0;
  for (int r = 1; r < colorsSize; ++r) {
    if (colors[r] != colors[r - 1]) {
      if (r + 1 - l >= k) ++count;
    } else {
      l = r;
    }
  }

  if (colors[0] != colors[colorsSize - 1]) {
    if (1 + colorsSize - l >= k) ++count;
    for (int r = 1; r + 1 < k; ++r) {
      if (colors[r] != colors[r - 1]) {
        if (r + 1 + colorsSize - l >= k) ++count;
      } else {
        break;
      }
    }
  }

  return count;
}
