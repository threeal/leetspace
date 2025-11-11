#include <string>
#include <vector>

class Solution {
 public:
  int findMaxForm(std::vector<std::string>& strs, int m, int n) {
    return strs.size() + m + n;
  }
};
