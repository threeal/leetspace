#include <vector>

class Solution {
 public:
  int findSmallestInteger(std::vector<int>& nums, int value) {
    std::vector<int> freqs(value, 0);
    for (const int num : nums) {
      ++freqs[(value + (num % value)) % value];
    }

    int candidate{0};
    for (int i{1}; i < value; ++i) {
      if (freqs[i] < freqs[candidate]) candidate = i;
    }

    return value * freqs[candidate] + candidate;
  }
};
