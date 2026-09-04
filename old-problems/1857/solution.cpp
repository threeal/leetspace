#include <string>
#include <vector>

class Solution {
 public:
  int largestPathValue(
      std::string colors, std::vector<std::vector<int>>& edges) {
    return colors.size() + edges.size();
  }
};
