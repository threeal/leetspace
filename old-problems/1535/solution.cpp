#include <vector>

class Solution {
 public:
  int getWinner(std::vector<int>& arr, int k) {
    int win = 0;
    std::size_t ref = 0;

    for (std::size_t i = 1; i < arr.size(); ++i) {
      if (win >= k) break;
      if (arr[i] > arr[ref]) {
        win = 1;
        ref = i;
      } else {
        ++win;
      }
    }

    return arr[ref];
  }
};
