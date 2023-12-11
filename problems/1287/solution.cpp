#include <vector>

class Solution {
 public:
  int findSpecialInteger(std::vector<int>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
      if (arr[i] == arr[i + arr.size() / 4]) return arr[i];
    }
    return 0;
  }
};
