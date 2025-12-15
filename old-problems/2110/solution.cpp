#include <vector>

class Solution {
 public:
  long long getDescentPeriods(std::vector<int>& prices) {
    std::size_t sum{1};
    for (std::size_t l{0}, r{1}; r < prices.size(); ++r) {
      if (prices[r - 1] - prices[r] != 1) l = r;
      sum += r - l + 1;
    }
    return sum;
  }
};
