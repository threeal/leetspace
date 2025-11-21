#include <string>
#include <vector>

class Solution {
 public:
  int maximumValue(std::vector<std::string>& strs) {
    int maxVal{0};
    for (const std::string& str : strs) {
      int val{0};
      for (const char c : str) {
        if (c >= '0' && c <= '9') {
          val = val * 10 + c - '0';
        } else {
          val = str.size();
          break;
        }
      }
      if (val > maxVal) maxVal = val;
    }
    return maxVal;
  }
};
