#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> beautifulArray(int n) {
    std::vector<int> res{};
    res.reserve(n);
    res.push_back(1);

    std::vector<int> prev{};
    prev.reserve(n);

    for (int i{2}; i <= n; ++i) {
      std::swap(prev, res);
      res.clear();

      for (int num : prev) {
        if (num * 2 - 1 <= i) res.push_back(num * 2 - 1);
      }

      for (int num : prev) {
        if (num * 2 <= i) res.push_back(num * 2);
      }
    }

    return res;
  }
};
