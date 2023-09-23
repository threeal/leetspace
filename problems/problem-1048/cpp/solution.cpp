class Solution {
 private:
  unordered_map<int, vector<string>> m;

 public:
  int longestStrChain(vector<string>& words) {
    for (const auto& word : words) {
      m[word.size()].push_back(word);
    }

    int max = 0;
    for (const auto& [n, strs] : m) {
      for (const auto& str : strs) {
        const int newMax = 1 + findMax(str, n + 1);
        if (newMax > max) max = newMax;
      }
    }

    return max;
  }

  int findMax(const std::string str, int index) {
    const auto it = m.find(index);
    if (it == m.end()) return 0;
    int max = 0;
    for (const auto& mstr : it->second) {
      if (!compare(mstr, str)) continue;
      const int newMax = 1 + findMax(mstr, index + 1);
      if (newMax > max) max = newMax;
    }
    return max;
  }

  bool compare(const std::string& a, const std::string& b) {
    auto ai = a.begin();
    auto bi = b.begin();

    const auto ae = a.end();
    const auto be = b.end();

    while (ai != ae && bi != be) {
      if (*ai != *bi) {
        ++ai;
        while (ai != ae && bi != be) {
          if (*ai != *bi) return false;
          ++ai;
          ++bi;
        }
        return ai == ae && bi == be;
        ;
      }
      ++ai;
      ++bi;
    }

    return ++ai == ae && bi == be;
  }
};
