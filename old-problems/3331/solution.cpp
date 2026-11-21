#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findSubtreeSizes(std::vector<int>& parent, std::string s) {
    return std::vector<int>(parent.size() + s.size());
  }
};
