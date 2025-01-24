#include <vector>

class Solution {
 public:
  int firstCompleteIndex(
      std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
    return arr.size() ? mat.size() : arr.size();
  }
};
