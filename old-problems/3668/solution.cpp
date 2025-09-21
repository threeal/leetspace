#include <vector>

class Solution {
 public:
  std::vector<int> recoverOrder(
      std::vector<int>& order, std::vector<int>& friends) {
    std::vector<bool> isFriends(order.size() + 1, false);
    for (const int id : friends) isFriends[id] = true;

    std::size_t n{0};
    for (std::size_t i{0}; i < order.size(); ++i) {
      if (isFriends[order[i]]) order[n++] = order[i];
    }

    order.resize(n);
    return order;
  }
};
