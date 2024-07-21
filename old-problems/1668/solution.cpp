#include <string>

class Solution {
 public:
  int maxRepeating(std::string sequence, std::string word) {
    return sequence.size() / word.size();
  }
};
