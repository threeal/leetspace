void quickSort(int* low, int* high);

int findContentChildren(int* g, int gSize, int* s, int sSize) {
  quickSort(g, g + gSize - 1);
  quickSort(s, s + sSize - 1);

  int gi = 0;
  int si = 0;
  while (gi < gSize && si < sSize) {
    if (g[gi] <= s[si]) ++gi;
    ++si;
  }

  return gi;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void quickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j >= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  quickSort(low, i - 1);
  quickSort(i + 1, high);
}
