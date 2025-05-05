#include <string>
#include <vector>

class Solution {
 public:
  std::string restoreString(std::string s, std::vector<int>& indices) {
    std::string out(s.size(), 0);
    for (std::size_t i{0}; i < indices.size(); ++i) {
      out[indices[i]] = s[i];
    }
    return out;
  }
};
