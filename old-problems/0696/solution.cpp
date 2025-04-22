#include <string>

class Solution {
 public:
  int countBinarySubstrings(std::string s) {
    int total{0}, zeros{0}, ones{0};
    std::size_t i{0};
    while (i < s.size()) {
      zeros = 0;
      while (i < s.size() && s[i] == '0') ++i, ++zeros;
      total += zeros <= ones ? zeros : ones;

      ones = 0;
      while (i < s.size() && s[i] == '1') ++i, ++ones;
      total += zeros <= ones ? zeros : ones;
    }
    return total;
  }
};
