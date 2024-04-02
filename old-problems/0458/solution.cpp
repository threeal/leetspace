#include <ctgmath>

class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return std::ceil(std::log2(buckets) / std::log2(minutesToTest / minutesToDie + 1));
  }
};
