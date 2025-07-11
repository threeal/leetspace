#include <vector>

class Solution {
 public:
  int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
    return meetings.size() % n;
  }
};
