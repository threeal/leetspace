#include <vector>

class Solution {
 public:
  int findTheDistanceValue(
      std::vector<int>& arr1, std::vector<int>& arr2, int d) {
    return arr1.size() + arr2.size() + d;
  }
};
