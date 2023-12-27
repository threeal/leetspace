#include <string>
#include <vector>

class Solution {
 public:
  int minCost(std::string colors, std::vector<int>& neededTime) {
    int total = 0;

    std::size_t left = 0;
    std::size_t right = 1;

    for (; right < colors.size(); ++right) {
      if (colors[left] == colors[right]) continue;
      int largest = 0;
      for (std::size_t i = left; i < right; ++i) {
        largest = std::max(largest, neededTime[i]);
        total += neededTime[i];
      }
      total -= largest;
      left = right;
    }

    int largest = 0;
    for (std::size_t i = left; i < right; ++i) {
      largest = std::max(largest, neededTime[i]);
      total += neededTime[i];
    }
    total -= largest;

    return total;
  }
};
