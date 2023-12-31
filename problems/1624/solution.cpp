#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
 public:
  int maxLengthBetweenEqualCharacters(std::string s) {
    int maxLength = -1;
    std::unordered_map<char, std::size_t> lefts;
    for (std::size_t i = 0; i < s.size(); ++i) {
      const auto it = lefts.find(s[i]);
      if (it == lefts.end()) {
        lefts.emplace(s[i], i);
      } else {
        maxLength = std::max<int>(maxLength, i - it->second - 1);
      }
    }
    return maxLength;
  }
};
