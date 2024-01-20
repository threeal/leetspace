#include <stdbool.h>

void quickSort(int* low, int* high);

bool closeStrings(char* word1, char* word2) {
  int word1Counts[26] = {0};
  while (*word1 != 0) {
    ++word1Counts[*word1 - 'a'];
    ++word1;
  }

  int word2Counts[26] = {0};
  while (*word2 != 0) {
    ++word2Counts[*word2 - 'a'];
    ++word2;
  }

  for (int i = 0; i < 26; ++i) {
    if ((word1Counts[i] > 0) != (word2Counts[i] > 0))
      return false;
  }

  quickSort(word1Counts, word1Counts + 25);
  quickSort(word2Counts, word2Counts + 25);

  for (int i = 0; i < 26; ++i) {
    if (word1Counts[i] != word2Counts[i])
      return false;
  }

  return true;
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
