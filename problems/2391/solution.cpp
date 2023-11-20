#include <string>
#include <vector>

// clang-format off
enum GarbageType { Metal = 0, Paper, Glass };
// clang-format on

class Solution {
 public:
  int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
    int totalTime[3] = {0};
    int travelTime[3] = {0};

    for (size_t i = 0; i < garbage.size(); ++i) {
      if (i > 0) {
        for (size_t j = 0; j < 3; ++j) {
          travelTime[j] += travel[i - 1];
        }
      }

      int time[3] = {0};
      for (const auto c : garbage[i]) {
        switch (c) {
          // clang-format off
          case 'M': ++time[Metal]; break;
          case 'P': ++time[Paper]; break;
          case 'G': ++time[Glass]; break;
            // clang-format on
        }
      }

      for (size_t j = 0; j < 3; ++j) {
        if (time[j] > 0) {
          totalTime[j] += travelTime[j] + time[j];
          travelTime[j] = 0;
        }
      }
    }

    return totalTime[Metal] + totalTime[Paper] + totalTime[Glass];
  }
};
