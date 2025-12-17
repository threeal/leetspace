#include <vector>

class Solution {
 public:
  int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    return arr.size() + k + threshold;
  }
};
