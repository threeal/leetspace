#include <vector>

class Solution {
 public:
  int findTheDistanceValue(
      std::vector<int>& arr1, std::vector<int>& arr2, int d) {
    std::sort(arr2.begin(), arr2.end());

    int count{0};
    for (int val : arr1) {
      const auto it1 = std::lower_bound(arr2.begin(), arr2.end(), val - d);
      const auto it2 = std::upper_bound(arr2.begin(), arr2.end(), val + d);
      if (it1 == it2) ++count;
    }

    return count;
  }
};
