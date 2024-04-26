#include <map>
#include <set>
#include <vector>

class Solution {
 public:
  std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
    std::map<int, std::set<int, std::less<int>>, std::less<int>> m;

    const int n = mat.size();
    for (int i = 0; i < n; ++i) {
      int total = 0;
      for (const auto v : mat[i]) {
        total += v;
      }

      m[total].insert(i);
    }

    int j = 0;
    std::vector<int> res(k);
    for (const auto& [total, s] : m) {
      for (const auto i : s) {
        res[j] = i;
        if (++j >= k) return res;
      }
    }

    return res;
  }
};
