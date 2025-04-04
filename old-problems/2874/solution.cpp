#include <vector>

class Solution {
 public:
  long long maximumTripletValue(std::vector<int>& nums) {
    long long maxTriplet{0}, maxDiff{0}, maxVal{0};
    for (const auto num : nums) {
      if (maxDiff * num > maxTriplet) maxTriplet = maxDiff * num;
      if (maxVal - num > maxDiff) maxDiff = maxVal - num;
      if (num > maxVal) maxVal = num;
    }
    return maxTriplet;
  }
};
