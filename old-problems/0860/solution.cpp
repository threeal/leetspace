#include <vector>

class Solution {
 public:
  bool lemonadeChange(std::vector<int>& bills) {
    int fives{0}, tens{0};
    for (const auto bill : bills) {
      switch (bill) {
        case 5:
          ++fives;
          break;

        case 10:
          if (fives <= 0) return false;
          --fives;
          ++tens;
          break;

        case 20:
          if (tens <= 0) {
            if (fives <= 2) return false;
            fives -= 3;
          } else {
            if (fives <= 0) return false;
            --fives;
            --tens;
          }
      }
    }

    return true;
  }
};
