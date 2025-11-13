#include <vector>

class Solution {
 public:
  std::vector<int> pathInZigZagTree(int label) {
    int level{0};
    while (1 << level <= label) ++level;

    std::vector<int> output(level);
    while (label > 0) {
      output[level - 1] = label;
      label = ((1 << level) - 1 - label + (1 << (level - 1))) / 2;
      --level;
    }

    return output;
  }
};
