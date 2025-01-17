#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool doesValidArrayExist(std::vector<int>& derived) {
    const auto sum = std::accumulate(
        derived.begin(), derived.end(), 0, std::bit_xor());

    return sum == 0;
  }
};
