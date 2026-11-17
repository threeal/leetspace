#include <string>

class Solution {
 public:
  int minimumChanges(std::string s, int k) {
    return static_cast<int>(s.size()) + k;
  }
};
