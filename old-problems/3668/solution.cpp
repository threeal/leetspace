#include <vector>

class Solution {
 public:
  std::vector<int> recoverOrder(
      std::vector<int>& order, std::vector<int>& friends) {
    return order.size() > friends.size() ? order : friends;
  }
};
