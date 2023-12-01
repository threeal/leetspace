#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 private:
  std::unordered_map<int, std::vector<std::string>> m;
  std::unordered_map<std::string, int> findMaxCache;

 public:
  int longestStrChain(std::vector<std::string>& words) {
    for (const auto& word : words) {
      m[word.size()].push_back(word);
    }

    int max = 0;
    for (const auto& [n, strs] : m) {
      for (const auto& str : strs) {
        const int newMax = 1 + findMax(str);
        if (newMax > max) max = newMax;
      }
    }

    return max;
  }

  int findMax(const std::string str) {
    const auto cacheIt = findMaxCache.find(str);
    if (cacheIt != findMaxCache.end())
      return cacheIt->second;
    const auto it = m.find(str.size() + 1);
    if (it == m.end()) {
      findMaxCache.emplace(str, 0);
      return 0;
    }
    int max = 0;
    for (const auto& mstr : it->second) {
      if (!compare(mstr, str)) continue;
      const int newMax = 1 + findMax(mstr);
      if (newMax > max) max = newMax;
    }
    findMaxCache.emplace(str, max);
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
