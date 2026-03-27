#include <vector>

class Solution {
 public:
  int minimumIndex(std::vector<int>& capacity, int itemSize) {
    return capacity.size() + itemSize;
  }
};
