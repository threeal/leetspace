#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> buildArray(std::vector<int>& target, int n) {
    std::vector<std::string> cmds;

    auto ti = target.begin();
    for (int i = 1; i <= n && ti != target.end(); ++i) {
      if (*ti == i) {
        cmds.push_back("Push");
        ++ti;
      } else {
        cmds.push_back("Push");
        cmds.push_back("Pop");
      }
    }

    return cmds;
  }
};
