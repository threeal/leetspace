#include <string>
#include <vector>

class Solution {
 public:
  bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
    auto w1 = word1.begin();
    auto w2 = word2.begin();

    auto c1 = w1->begin();
    auto c2 = w2->begin();

    while (w1 != word1.end() && w2 != word2.end()) {
      if (*c1 != *c2) return false;
      if (++c1 == w1->end() && ++w1 != word1.end()) c1 = w1->begin();
      if (++c2 == w2->end() && ++w2 != word2.end()) c2 = w2->begin();
    }

    return w1 == word1.end() && w2 == word2.end();
  }
};
