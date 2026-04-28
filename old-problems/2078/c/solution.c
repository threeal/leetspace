int maxDistance(int* colors, int colorsSize) {
  if (colors[0] != colors[colorsSize - 1]) return colorsSize - 1;

  int l = 0, r = colorsSize - 1;
  while (colors[l] == colors[0]) ++l;
  while (colors[r] == colors[0]) --r;

  return r > colorsSize - l - 1 ? r : colorsSize - l - 1;
}
