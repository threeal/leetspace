#include <map>
#include <vector>

class Solution {
 public:
  int reductionOperations(std::vector<int>& nums) {
    std::map<int, int, std::greater<int>> frequencies;
    for (const auto num : nums) {
      ++frequencies[num];
    }

    frequencies.erase(std::prev(frequencies.end()));

    int operations = 0;
    for (const auto [num, freq] : frequencies) {
      operations += operations + freq;
    }

    return operations;
  }
};
