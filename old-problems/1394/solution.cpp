#include <algorithm>
#include <vector>

class Solution {
 public:
  int findLucky(std::vector<int>& arr) {
    const int n = arr.size();
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    int l{0};
    for (int r{1}; r < n; ++r) {
      if (arr[r] != arr[r - 1]) {
        if (r - l == arr[r - 1]) return arr[r - 1];
        l = r;
      }
    }

    return (n - l == arr.back()) ? arr.back() : -1;
  }
};
