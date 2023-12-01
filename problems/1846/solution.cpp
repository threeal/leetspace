// The solution can be done simply by sorting the array from lowest to highest
// and then iterating through the array following the rules so that the difference between each element should be equal to or less than 1.

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
    // Sort the array from the lowest to the highest.
    std::sort(arr.begin(), arr.end());

    // Iterating through the elements for calculating the highest possible value.
    // The highest value is at the end of the array, but each next element should be capped if the difference is more than 1.
    int res = 0;
    for (const auto num : arr) {
      res = std::min(res + 1, num);
    }

    return res;
  }
};
