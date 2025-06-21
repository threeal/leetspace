#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> getWordsInLongestSubsequence(
      std::vector<std::string>& words, std::vector<int>& groups) {
    std::vector<std::size_t> lengths(words.size());
    std::vector<std::size_t> prevs(words.size());

    std::size_t maxI = 0;
    lengths[0] = 1;

    for (std::size_t i{1}; i < words.size(); ++i) {
      lengths[i] = 1;
      for (std::size_t j{i}; j > 0; --j) {
        if (lengths[j - 1] + 1 >= lengths[i] &&
            groups[j - 1] != groups[i] &&
            words[j - 1].size() == words[i].size() &&
            validHammingDistance(words[j - 1], words[i])) {
          lengths[i] = lengths[j - 1] + 1;
          prevs[i] = j - 1;

          if (lengths[i] > lengths[maxI]) maxI = i;
        }
      }
    }

    std::vector<std::string> output(lengths[maxI]);
    for (std::size_t i{output.size()}; i > 0; --i) {
      output[i - 1] = words[maxI];
      maxI = prevs[maxI];
    }

    return output;
  }

 private:
  static bool validHammingDistance(const std::string& a, const std::string& b) {
    for (std::size_t i{0}; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        while (++i < a.size()) {
          if (a[i] != b[i]) return false;
        }
        return true;
      }
    }
    return false;
  }
};
