#include <string>

class Solution {
 public:
  std::string getEncryptedString(std::string s, int k) {
    std::string out(s.size(), ' ');
    for (std::size_t i{0}; i < s.size(); ++i) {
      out[i] = s[(i + k) % s.size()];
    }
    return out;
  }
};
