#include <vector>

class Solution {
 public:
  int countDays(int days, std::vector<std::vector<int>>& meetings) {
    return days - meetings.size();
  }
};
