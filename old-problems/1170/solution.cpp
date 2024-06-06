#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

class Solution {
 public:
  std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
    std::vector<int> frequencies(words.size());
    for (int i = words.size() - 1; i >= 0; --i) {
      frequencies[i] = calculateFrequency(words[i]);
    }
    std::sort(frequencies.begin(), frequencies.end());

    std::vector<int> output(queries.size());
    for (int i = queries.size() - 1; i >= 0; --i) {
      const int frequency{calculateFrequency(queries[i])};
      const auto it = std::upper_bound(frequencies.begin(), frequencies.end(), frequency);
      output[i] = std::distance(it, frequencies.end());
    }

    return output;
  }

  int calculateFrequency(std::string_view v) {
    char c = v[0];
    int frequency = 1;
    for (int i = v.size() - 1; i > 0; --i) {
      if (v[i] <= c) {
        if (v[i] == c) {
          ++frequency;
        } else {
          c = v[i];
          frequency = 1;
        }
      }
    }
    return frequency;
  }
};
