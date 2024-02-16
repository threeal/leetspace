#include <vector>

class Solution {
 public:
  int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
    return arr.size() - k;
  }
};
