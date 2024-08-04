#include <string>
#include <vector>

class Solution {
 public:
  int countSeniors(std::vector<std::string>& details) {
    int count{0};
    for (const auto& detail : details) {
      if (detail[11] > '6') {
        ++count;
      } else if (detail[11] == '6' && detail[12] > '0') {
        ++count;
      }
    }
    return count;
  }
};
