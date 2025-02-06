#include <vector>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<int> arr(m, 1);
    for (int i{1}; i < n; ++i) {
      for (int j{1}; j < m; ++j) {
        arr[j] += arr[j - 1];
      }
    }
    return arr.back();
  }
};
