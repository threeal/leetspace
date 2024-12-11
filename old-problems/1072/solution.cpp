#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix) {
    std::unordered_map<std::string, int> freqs{};
    for (const auto& row : matrix) {
      std::string key{};
      const auto flip = row.front() == 1;
      for (const auto val : row) {
        key += flip ? (val == 0 ? 1 : 0) : val;
      }

      const auto it = freqs.find(key);
      if (it == freqs.end()) {
        freqs.emplace(key, 1);
      } else {
        ++(it->second);
      }
    }

    int maxFreq{0};
    for (const auto& [key, freq] : freqs) {
      if (freq > maxFreq) maxFreq = freq;
    }

    return maxFreq;
  }
};
