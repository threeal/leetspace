#include <string>

class Solution {
 public:
  int titleToNumber(std::string columnTitle) {
    int num{columnTitle[columnTitle.size() - 1] + 1 - 'A'}, pow{1};
    for (std::size_t i{1}; i < columnTitle.size(); ++i) {
      pow *= 26;
      num += (columnTitle[columnTitle.size() - i - 1] + 1 - 'A') * pow;
    }
    return num;
  }
};
