#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minSetSize(std::vector<int>& arr) {
    std::unordered_map<int, int> numFreqs{};
    for (int num : arr) ++numFreqs[num];

    std::vector<int> freqs{};
    freqs.reserve(numFreqs.size());

    for (const auto [num, freq] : numFreqs) {
      freqs.push_back(freq);
    }

    std::sort(freqs.begin(), freqs.end(), std::greater<int>());

    int i{0}, left = arr.size() / 2;
    while (left > 0) left -= freqs[i++];

    return i;
  }
};
