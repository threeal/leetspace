#include <vector>

class Solution {
 public:
  int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
    return days.size() * costs.size();
  }
};
