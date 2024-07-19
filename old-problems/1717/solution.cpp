#include <string>

class Solution {
 public:
  int maximumGain(std::string s, int x, int y) {
    int gain{0};
    int aCount{0};
    int bCount{0};

    if (x < y) {
      for (const auto c : s) {
        switch (c) {
          case 'a':
            if (bCount > 0) {
              gain += y;
              --bCount;
            } else {
              ++aCount;
            }
            break;

          case 'b':
            ++bCount;
            break;

          default:
            gain += std::min(aCount, bCount) * x;
            aCount = 0;
            bCount = 0;
        }
      }

      return gain + std::min(aCount, bCount) * x;
    }

    for (const auto c : s) {
      switch (c) {
        case 'a':
          ++aCount;
          break;

        case 'b':
          if (aCount > 0) {
            gain += x;
            --aCount;
          } else {
            ++bCount;
          }
          break;

        default:
          gain += std::min(aCount, bCount) * y;
          aCount = 0;
          bCount = 0;
      }
    }

    return gain + std::min(aCount, bCount) * y;
  }
};
