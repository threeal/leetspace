#include <vector>

class Solution {
 public:
  long long pickGifts(std::vector<int>& gifts, int k) {
    return gifts.size() * k;
  }
};
