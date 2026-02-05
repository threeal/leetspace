int numberOfAlternatingGroups(int* colors, int colorsSize) {
  int count = 0;

  if (colors[0] != colors[colorsSize - 1] &&
      colors[0] == colors[colorsSize - 2]) ++count;

  if (colors[1] != colors[0] && colors[1] == colors[colorsSize - 1]) ++count;

  for (int i = 2; i < colorsSize; ++i) {
    if (colors[i] != colors[i - 1] && colors[i] == colors[i - 2]) ++count;
  }

  return count;
}
