#include <string>
#include <vector>

class Solution {
 public:
  int finalValueAfterOperations(std::vector<std::string>& operations) {
    int val{0};
    for (const std::string& operation : operations) {
      if (operation[1] == '+') {
        ++val;
      } else {
        --val;
      }
    }
    return val;
  }
};
