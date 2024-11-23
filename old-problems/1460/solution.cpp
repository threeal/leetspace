#include <algorithm>
#include <vector>

class Solution {
 public:
  bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
    std::sort(target.begin(), target.end());
    std::sort(arr.begin(), arr.end());
    return target == arr;
  }
};
