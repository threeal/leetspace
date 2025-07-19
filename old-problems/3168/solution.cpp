#include <string>

class Solution {
 public:
  int minimumChairs(std::string s) {
    int maxChairs{0}, chairs{0};
    for (const char c : s) {
      if (c == 'E') {
        if (++chairs > maxChairs) maxChairs = chairs;
      } else {
        --chairs;
      }
    }
    return maxChairs;
  }
};
