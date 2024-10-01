#include <vector>

class Solution {
 public:
  bool canArrange(std::vector<int>& arr, int k) {
    return arr.front() == k;
  }
};
