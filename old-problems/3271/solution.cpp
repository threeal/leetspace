#include <string>

class Solution {
 public:
  std::string stringHash(std::string s, int k) {
    for (std::size_t i{0}; i < s.size(); i += k) {
      char hash{0};
      for (int j{0}; j < k; ++j) {
        hash = (hash + s[i + j] - 'a') % 26;
      }
      s[i / k] = 'a' + hash;
    }
    s.resize(s.size() / k);
    return s;
  }
};
