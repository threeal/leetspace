#include <string>

class Solution {
 public:
  bool canConstruct(std::string s, int k) {
    return s.size() == static_cast<std::size_t>(k);
  }
};
