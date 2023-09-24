class Solution {
 public:
  bool isSubsequence(string s, string t) {
    auto si = s.begin();
    const auto se = s.end();
    if (si == se) return true;

    for (const auto c : t) {
      if (*si != c) continue;
      if (++si == se) return true;
    }

    return false;
  }
};
