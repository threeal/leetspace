#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> divideString(std::string s, int k, char fill) {
    std::vector<std::string> output((s.size() + k - 1) / k);
    for (std::size_t i{0}; i < s.size(); i += k) {
      output[i / k] = s.substr(i, k);
    }
    output.back().resize(k, fill);
    return output;
  }
};
