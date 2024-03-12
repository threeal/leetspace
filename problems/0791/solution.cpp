#include <string>
#include <vector>

class Solution {
 public:
  std::string customSortString(std::string order, std::string s) {
    std::vector<std::uint_fast8_t> orderOf(26, 0);
    for (std::uint_fast8_t i = 0; i < order.size(); ++i) {
      orderOf[order[i] - 'a'] = i;
    }

    std::sort(s.begin(), s.end(), [&](const char a, const char b) {
      return orderOf[a - 'a'] < orderOf[b - 'a'];
    });

    return s;
  }
};
