#include <vector>

class Solution {
 public:
  double averageWaitingTime(std::vector<std::vector<int>>& customers) {
    double totalWaitTime{0.0};

    int currentTime{0};
    for (const auto& customer : customers) {
      if (currentTime > customer[0]) {
        totalWaitTime += currentTime - customer[0];
      } else {
        currentTime = customer[0];
      }
      currentTime += customer[1];
      totalWaitTime += customer[1];
    }

    return totalWaitTime / customers.size();
  }
};
