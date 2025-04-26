#include <string>

class Solution {
 public:
  int numJewelsInStones(std::string jewels, std::string stones) {
    return jewels.size() + stones.size();
  }
};
