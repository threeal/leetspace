class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    map<int, set<int, less<int>>, less<int>> m;

    const int n = mat.size();
    for (int i = 0; i < n; ++i) {
      int total = 0;
      for (const auto v : mat[i]) {
        total += v;
      }

      m[total].insert(i);
    }

    int j = 0;
    vector<int> res(k);
    for (const auto& [total, s] : m) {
      for (const auto i : s) {
        res[j] = i;
        if (++j >= k) return res;
      }
    }

    return res;
  }
};
