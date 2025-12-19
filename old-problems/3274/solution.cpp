#include <string>

class Solution {
 public:
  bool checkTwoChessboards(std::string coordinate1, std::string coordinate2) {
    return (coordinate1[0] + coordinate1[1]) % 2 ==
        (coordinate2[0] + coordinate2[1]) % 2;
  }
};
