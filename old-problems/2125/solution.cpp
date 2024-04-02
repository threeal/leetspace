#include <string>
#include <vector>

class Solution {
 public:
  int numberOfBeams(std::vector<std::string>& bank) {
    int lasers = 0;
    int prevBeams = 0;

    for (const auto& row : bank) {
      int beams = 0;
      for (const auto c : row) {
        if (c == '1') ++beams;
      }

      if (beams > 0) {
        lasers += prevBeams * beams;
        prevBeams = beams;
      }
    }

    return lasers;
  }
};
