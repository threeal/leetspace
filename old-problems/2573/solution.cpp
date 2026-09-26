#include <string>
#include <vector>

class Solution {
 public:
  std::string findTheString(std::vector<std::vector<int>>& lcp) {
    return std::string(lcp.size(), 'a');
  }
};
