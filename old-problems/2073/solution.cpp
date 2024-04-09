#include <algorithm>
#include <vector>

class Solution {
 public:
  int timeRequiredToBuy(std::vector<int>& tickets, int k) {
    int sum{tickets[k]};

    for (int i{0}; i < k; ++i) {
      sum += std::min(tickets[i], tickets[k]);
    }

    for (int i{k + 1}; i < static_cast<int>(tickets.size()); ++i) {
      sum += std::min(tickets[i], tickets[k] - 1);
    }

    return sum;
  }
};
