#include <string>

class Solution {
 public:
  int maxRepeating(std::string sequence, std::string word) {
    int maxRepeating{0};
    for (int i = word.size() - 1; i >= 0; --i) {
      int repeating{0};
      for (int j = sequence.size() - word.size() - i; j >= 0; j -= word.size()) {
        for (int k = word.size() - 1; k >= 0; --k) {
          if (sequence[j + k] != word[k]) {
            repeating = -1;
            break;
          }
        }
        if (++repeating > 0) {
          if (maxRepeating < repeating) maxRepeating = repeating;
        }
      }
    }
    return maxRepeating;
  }
};
