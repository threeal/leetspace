static int output[2];

int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
  (void)widthsSize;

  int lines = 1, width = 0;
  for (char* c = s; *c != 0; ++c) {
    if (width + widths[*c - 'a'] > 100) {
      ++lines;
      width = 0;
    }
    width += widths[*c - 'a'];
  }

  output[0] = lines;
  output[1] = width;

  *returnSize = 2;
  return output;
}
