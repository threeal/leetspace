#include <string>
#include <vector>

class Solution {
 public:
  bool pyramidTransition(
      std::string bottom, std::vector<std::string>& allowed) {
    return bottom.empty() && allowed.empty();
  }
};
