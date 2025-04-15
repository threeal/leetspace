#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  std::string frequencySort(std::string s) {
    std::vector<int> freqs('z' - '0' + 1, 0);
    for (const char c : s) ++freqs[c - '0'];

    std::vector<char> indices('z' - '0' + 1);
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(), [&](const char a, const char b) {
      return freqs[a] == freqs[b] ? a < b : freqs[a] > freqs[b];
    });

    std::size_t i{0};
    for (const char index : indices) {
      for (int n{freqs[index]}; n > 0; --n) {
        s[i++] = '0' + index;
      }
    }

    return s;
  }
};
