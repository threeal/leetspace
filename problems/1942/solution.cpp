#include <vector>

class Solution {
 public:
  int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
    return times.size() - targetFriend;
  }
};
