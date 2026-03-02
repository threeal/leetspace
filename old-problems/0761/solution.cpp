#include <string>
#include <string_view>
#include <vector>

class Solution {
 public:
  std::string makeLargestSpecial(std::string s) {
    sortSpecial(s, 0, s.size());
    return s;
  }

 private:
  static void sortSpecial(std::string& s, std::size_t i, std::size_t n) {
    std::string ss{s.substr(i, n)};
    std::string_view ssv{ss};

    std::vector<std::string_view> splits{};
    for (std::size_t count{0}, l{0}, r{0}; r < ssv.size(); ++r) {
      if (ssv[r] == '0') {
        if (--count == 0) {
          if (r - l > 2) sortSpecial(ss, l + 1, r - 1 - l);
          splits.push_back(ssv.substr(l, r + 1 - l));
          l = r + 1;
        }
      } else {
        ++count;
      }
    }

    std::sort(splits.begin(), splits.end(), std::greater<std::string_view>());
    for (const std::string_view& split : splits) {
      for (const char c : split) {
        s[i++] = c;
      }
    }
  }
};
