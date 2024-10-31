#include <vector>

class Solution {
 public:
  long long minimumTotalDistance(
      std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
    return robot.size() * factory.size();
  }
};
