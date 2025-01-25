#include <string>

class Solution {
 public:
  int strStr(std::string haystack, std::string needle) {
    if (haystack.size() >= needle.size()) {
      for (std::size_t i{0}; i <= haystack.size() - needle.size(); ++i) {
        if (haystack.compare(i, needle.size(), needle) == 0) return i;
      }
    }
    return -1;
  }
};
