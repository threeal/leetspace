#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int strangePrinter(std::string s) {
    std::size_t n{0}, i{0};
    while (i < s.size()) {
      s[n] = s[i];
      ++i;
      while (i < s.size() && s[i] == s[n]) ++i;
      ++n;
    }
    s.resize(n);

    std::vector<std::vector<int>> caches(s.size());
    for (std::size_t i{0}; i < caches.size(); ++i) {
      caches[i].resize(caches.size() - i, -1);
    }

    return strangePrinterRange(caches.data(), s.data(), 0, s.size() - 1);
  }

 private:
  int strangePrinterRange(
      std::vector<int>* caches, const char* s, int l, int r) {
    if (r - l < 0) return 0;

    int& cache = caches[l][r - l];
    if (cache < 0) {
      cache = 1 + strangePrinterRange(caches, s, l + 1, r);
      for (int i{l + 1}; i <= r; ++i) {
        if (s[i] == s[l]) {
          const auto res = strangePrinterRange(caches, s, l, i - 1) +
              strangePrinterRange(caches, s, i + 1, r);
          cache = std::min(res, cache);
        }
      }
    }

    return cache;
  }
};
