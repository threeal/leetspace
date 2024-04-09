#include <algorithm>
#include <vector>

class Solution {
 public:
  int timeRequiredToBuy(std::vector<int>& tickets, int k) {
    int target{tickets[k]};
    int sum{target};

    for (int i{0}; i < k; ++i) {
      sum += std::min(tickets[i], target);
    }

    --target;
    for (int i{k + 1}; i < static_cast<int>(tickets.size()); ++i) {
      sum += std::min(tickets[i], target);
    }

    return sum;
  }
};
