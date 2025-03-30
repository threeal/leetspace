#include <algorithm>
#include <vector>

class Solution {
 public:
  int countDays(int days, std::vector<std::vector<int>>& meetings) {
    std::sort(meetings.begin(), meetings.end());

    int totalDay{0}, day{1};
    for (const auto& meeting : meetings) {
      if (meeting[0] > day) totalDay += meeting[0] - day;
      if (meeting[1] >= day) day = meeting[1] + 1;
    }

    if (days >= day) totalDay += days - day + 1;

    return totalDay;
  }
};
