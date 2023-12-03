#include <stdbool.h>
#include <string.h>

int countCharacters(char** words, int wordsSize, char* chars) {
  int charCounts[26] = {0};

  // Count each character in the `chars` string.
  while (*chars != 0) {
    ++charCounts[*chars - 'a'];
    ++chars;
  }

  // Check if each string in `words` is good.
  int totalSum = 0;
  for (int i = 0; i < wordsSize; ++i) {
    bool isGood = true;

    // Copy the counting array
    int counts[26];
    memcpy(counts, charCounts, 26 * sizeof(int));

    // Decrement the counting array to check if the string is good.
    int j = 0;
    while (words[i][j] != 0) {
      if (--counts[words[i][j] - 'a'] < 0) {
        isGood = false;
        break;
      }
      ++j;
    }

    // Sum the length of the string if it is good.
    if (isGood) totalSum += j;
  }

  return totalSum;
}
