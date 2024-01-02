void quickSort(int* low, int* high);

int findContentChildren(int* g, int gSize, int* s, int sSize) {
  for (int i = 1; i < gSize; ++i) {
    if (g[i - 1] > g[i]) {
      quickSort(g, g + gSize - 1);
      break;
    }
  }

  for (int i = 1; i < sSize; ++i) {
    if (s[i - 1] > s[i]) {
      quickSort(s, s + sSize - 1);
      break;
    }
  }

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
