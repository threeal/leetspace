#include <string>
#include <vector>

class Solution {
 public:
  std::string mapWordWeights(
      std::vector<std::string>& words, std::vector<int>& weights) {
    std::string output(words.size(), 'z');
    for (std::size_t i{0}; i < words.size(); ++i) {
      int sum{0};
      for (const char c : words[i]) sum += weights[c - 'a'];
      output[i] -= sum % 26;
    }
    return output;
  }
};
