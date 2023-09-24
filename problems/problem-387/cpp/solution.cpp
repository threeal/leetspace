class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_set<char> duplicates;
    map<char, int> uniques;

    const int n = s.size();
    for (int i = 0; i < n; ++i) {
      auto c = s[i];
      if (duplicates.contains(c)) continue;
      auto it = uniques.find(c);
      if (it == uniques.end()) {
        uniques[c] = i;
      } else {
        uniques.erase(it);
        duplicates.insert(c);
      }
    }

    if (uniques.empty()) return -1;

    int lowest = n;
    for (auto [c, i] : uniques) {
      if (i < lowest) lowest = i;
    }
    return lowest;
  }
};
