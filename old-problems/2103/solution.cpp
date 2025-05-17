#include <string>

class Solution {
 public:
  int countPoints(std::string rings) {
    char rods[10]{0};
    for (std::size_t i{1}; i < rings.size(); i += 2) {
      switch (rings[i - 1]) {
        case 'B':
          rods[rings[i] - '0'] |= 1;
          break;

        case 'G':
          rods[rings[i] - '0'] |= 2;
          break;

        case 'R':
          rods[rings[i] - '0'] |= 4;
          break;
      }
    }

    int count{0};
    for (int i{0}; i < 10; ++i) {
      if (rods[i] == 7) ++count;
    }

    return count;
  }
};
