#include <vector>

class Solution {
 public:
  bool checkIfExist(std::vector<int>& arr) {
    std::vector<bool> exists(2001, false);
    for (const auto num : arr) {
      if (num >= -500 && num <= 500 && exists[1000 + num * 2]) {
        return true;
      } else if (num % 2 == 0 && exists[1000 + num / 2]) {
        return true;
      }
      exists[1000 + num] = true;
    }
    return false;
  }
};
