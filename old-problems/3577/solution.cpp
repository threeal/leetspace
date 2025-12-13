#include <vector>

class Solution {
 public:
  int countPermutations(std::vector<int>& complexity) {
    for (std::size_t i{1}; i < complexity.size(); ++i) {
      if (complexity[i] <= complexity[0]) return 0;
    }

    long long count{1};
    for (long long i{2}, r = complexity.size(); i < r; ++i) {
      count = (count * i) % 1000000007;
    }

    return count;
  }
};
