#include <vector>

class Solution {
 public:
  bool threeConsecutiveOdds(std::vector<int>& arr) {
    int i = arr.size() - 3;
    while (i >= 0) {
      if (arr[i] % 2 != 0) {
        if (arr[i + 1] % 2 != 0) {
          if (arr[i + 2] % 2 != 0) {
            return true;
          } else {
            --i;
          }
        } else {
          i -= 2;
        }
      } else {
        i -= 3;
      }
    }
    return false;
  }
};
