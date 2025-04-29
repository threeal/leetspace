#include <string>

class Solution {
 public:
  int numJewelsInStones(std::string jewels, std::string stones) {
    bool isJewel[58]{false};
    for (const char c : jewels) isJewel[c - 'A'] = true;

    int count{0};
    for (const char c : stones) {
      if (isJewel[c - 'A']) ++count;
    }

    return count;
  }
};
