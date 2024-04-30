#include <string>
#include <vector>

class Solution {
 public:
  long long wonderfulSubstrings(std::string word) {
    long long count{0};
    std::vector<int> frequencies(1024, 0);
    frequencies[0] = 1;
    int sum{0};
    for (const auto c : word) {
      sum ^= 1 << (c - 'a');
      count += frequencies[sum]++ + frequencies[sum ^ 1] + frequencies[sum ^ 2] + frequencies[sum ^ 4] + frequencies[sum ^ 8] + frequencies[sum ^ 16] + frequencies[sum ^ 32] + frequencies[sum ^ 64] + frequencies[sum ^ 128] + frequencies[sum ^ 256] + frequencies[sum ^ 512];
    }
    return count;
  }
};
