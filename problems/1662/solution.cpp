// This problem can simply be solved by using iterators and a while loop.

#include <string>
#include <vector>

class Solution {
 public:
  bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
    // Initialize the word iterators.
    auto w1 = word1.begin();
    auto w2 = word2.begin();

    // Initialize the character iterators.
    auto c1 = w1->begin();
    auto c2 = w2->begin();

    // Repeat until both word iterators are not ended.
    while (w1 != word1.end() && w2 != word2.end()) {
      // Compare characters.
      if (*c1 != *c2) return false;

      // Increment the character iterators. If any is ended, increment the word iterator.
      if (++c1 == w1->end() && ++w1 != word1.end()) c1 = w1->begin();
      if (++c2 == w2->end() && ++w2 != word2.end()) c2 = w2->begin();
    }

    // Make sure if both word iterators are ended.
    return w1 == word1.end() && w2 == word2.end();
  }
};
