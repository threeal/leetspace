#include <string>
#include <vector>

class Solution {
 public:
  int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
    int metalTotalTime = 0, paperTotalTime = 0, glassTotalTime = 0;
    int metalTravelTime = 0, paperTravelTime = 0, glassTravelTime = 0;
    for (size_t i = 0; i < garbage.size(); ++i) {
      if (i > 0) {
        metalTravelTime += travel[i - 1];
        paperTravelTime += travel[i - 1];
        glassTravelTime += travel[i - 1];
      }

      int metalTime = 0, paperTime = 0, glassTime = 0;
      for (const auto c : garbage[i]) {
        switch (c) {
          case 'M':
            ++metalTime;
            break;
          case 'P':
            ++paperTime;
            break;
          case 'G':
            ++glassTime;
            break;
        }
      }

      if (metalTime > 0) {
        metalTotalTime += metalTravelTime + metalTime;
        metalTravelTime = 0;
      }

      if (paperTime > 0) {
        paperTotalTime += paperTravelTime + paperTime;
        paperTravelTime = 0;
      }

      if (glassTime > 0) {
        glassTotalTime += glassTravelTime + glassTime;
        glassTravelTime = 0;
      }
    }

    return metalTotalTime + paperTotalTime + glassTotalTime;
  }
};
