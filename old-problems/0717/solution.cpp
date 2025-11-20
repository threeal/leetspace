#include <vector>

class Solution {
 public:
  bool isOneBitCharacter(std::vector<int>& bits) {
    int i = bits.size() - 2;
    while (i >= 0 && bits[i] == 1) --i;
    return (bits.size() - i) % 2 == 0;
  }
};
