#include <vector>

class Solution {
 public:
  bool canReach(std::vector<int>& arr, int start) {
    return arr.front() == start;
  }
};
