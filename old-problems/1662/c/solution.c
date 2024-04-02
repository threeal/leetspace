// This problem can simply be solved by using iterators and a while loop.

#include <stdbool.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
  // Initialize the word iterators.
  char** w1 = word1;
  char** w2 = word2;

  // Initialize the character iterators.
  char* c1 = *w1;
  char* c2 = *w2;

  // Repeat until both word iterators are not ended.
  word1 += word1Size;
  word2 += word2Size;
  while (w1 < word1 && w2 < word2) {
    // Compare characters.
    if (*c1 != *c2) return false;

    // Increment the character iterators. If any is ended, increment the word iterator.
    if (*(++c1) == 0 && ++w1 < word1) c1 = *w1;
    if (*(++c2) == 0 && ++w2 < word2) c2 = *w2;
  }

  // Make sure if both word iterators are ended.
  return w1 == word1 && w2 == word2;
}
