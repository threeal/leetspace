#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  int numSpecialEquivGroups(std::vector<std::string>& words) {
    std::string str(words.front());

    std::vector<std::size_t> indices0((str.size() + 1) / 2);
    for (std::size_t i{0}; i < indices0.size(); ++i) indices0[i] = i * 2;

    std::vector<std::size_t> indices1(str.size() / 2);
    for (std::size_t i{0}; i < indices1.size(); ++i) indices1[i] = i * 2 + 1;

    for (std::string& word : words) {
      std::sort(
          indices0.begin(), indices0.end(),
          [&](const std::size_t a, const std::size_t b) {
            return word[a] < word[b];
          });

      std::sort(
          indices1.begin(), indices1.end(),
          [&](const std::size_t a, const std::size_t b) {
            return word[a] < word[b];
          });

      for (std::size_t i{0}; i < indices0.size(); ++i) {
        str[i * 2] = word[indices0[i]];
      }

      for (std::size_t i{0}; i < indices1.size(); ++i) {
        str[i * 2 + 1] = word[indices1[i]];
      }

      word = str;
    }

    std::sort(words.begin(), words.end());

    int count{1};
    for (std::size_t i{1}; i < words.size(); ++i) {
      if (words[i] != words[i - 1]) ++count;
    }

    return count;
  }
};
