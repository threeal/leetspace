#include <string>
#include <vector>

class Solution {
 public:
  int minCost(std::string colors, std::vector<int>& neededTime) {
    colors += ' ';

    int total = 0;

    std::size_t left = 0;
    for (std::size_t right = 1; right < colors.size(); ++right) {
      if (colors[left] != colors[right]) {
        if (right - left > 1) {
          int largest = 0;
          for (std::size_t i = left; i < right; ++i) {
            largest = std::max(largest, neededTime[i]);
            total += neededTime[i];
          }
          total -= largest;
        }
        left = right;
      }
    }

    return total;
  }
};
