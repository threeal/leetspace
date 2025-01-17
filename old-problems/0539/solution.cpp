#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int findMinDifference(std::vector<std::string>& timePoints) {
    std::vector<int> minutes(timePoints.size());
    for (int i = timePoints.size() - 1; i >= 0; --i) {
      minutes[i] = (timePoints[i][0] - '0') * 600 +
          (timePoints[i][1] - '0') * 60 +
          (timePoints[i][3] - '0') * 10 +
          (timePoints[i][4] - '0');
    }

    std::sort(minutes.begin(), minutes.end());

    int min{24 * 60 + minutes.front() - minutes.back()};
    for (int i = minutes.size() - 1; i > 0; --i) {
      if (minutes[i] - minutes[i - 1] < min) min = minutes[i] - minutes[i - 1];
    }

    return min;
  }
};
