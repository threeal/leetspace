#include <algorithm>
#include <string>

class Solution {
 public:
  int minTimeToType(std::string word) {
    int steps{std::min(word[0] - 'a', 26 - word[0] + 'a')};
    for (std::size_t i{1}; i < word.size(); ++i) {
      steps += word[i] >= word[i - 1]
          ? std::min(word[i] - word[i - 1], 26 - word[i] + word[i - 1])
          : std::min(word[i - 1] - word[i], 26 - word[i - 1] + word[i]);
    }
    return steps + word.size();
  }
};
