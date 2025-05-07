#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> cellsInRange(std::string s) {
    std::vector<std::string> output(
        (s[3] + 1 - s[0]) * (s[4] + 1 - s[1]), "A1");

    std::size_t n{0};
    for (char i{s[0]}; i <= s[3]; ++i) {
      for (char j{s[1]}; j <= s[4]; ++j) {
        output[n][0] = i;
        output[n][1] = j;
        ++n;
      }
    }

    return output;
  }
};
