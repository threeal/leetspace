#include <string>
#include <utility>

class Solution {
 public:
  bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
    if (sentence1.size() < sentence2.size()) std::swap(sentence1, sentence2);

    int prevSpace{-1};
    for (int i = 0; i < static_cast<int>(sentence2.size()); ++i) {
      if (sentence1[i] != sentence2[i]) {
        goto backward;
      } else if (sentence2[i] == ' ') {
        prevSpace = i;
      }
    }

    if (sentence1.size() == sentence2.size()) return true;
    if (sentence1[sentence2.size()] == ' ') return true;

  backward:
    int nextSpace = sentence2.size();
    int j1 = sentence1.size() - 1;
    int j2 = sentence2.size() - 1;
    while (j2 >= 0) {
      if (sentence1[j1] != sentence2[j2]) return false;
      if (sentence2[j2] == ' ') {
        nextSpace = j2;
        if (nextSpace == prevSpace) return true;
      }
      --j1;
      --j2;
    }
    return j1 < 0 || sentence1[j1] == ' ';
  }
};
