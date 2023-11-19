// The solution can be done simply by counting the frequencies and then
// iterating through the frequencies from largest to smallest to count the required number of operations.

#include <map>
#include <vector>

class Solution {
 public:
  int reductionOperations(std::vector<int>& nums) {
    // Count the frequencies; the map will be sorted from largest to smallest upon inserting a new value.
    std::map<int, int, std::greater<int>> frequencies;
    for (const auto num : nums) {
      ++frequencies[num];
    }

    // Remove the last value (the smallest value) from the map.
    frequencies.erase(std::prev(frequencies.end()));

    // Iterating through the frequencies to count the required number of operations.
    int freqs = 0;
    int operations = 0;
    for (const auto [num, freq] : frequencies) {
      freqs += freq;
      operations += freqs;
    }

    return operations;
  }
};
