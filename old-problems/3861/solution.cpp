#include <vector>

class Solution {
 public:
  int minimumIndex(std::vector<int>& capacity, int itemSize) {
    int idx{-1};
    for (std::size_t i{0}; i < capacity.size(); ++i) {
      if (capacity[i] >= itemSize &&
          (idx == -1 || capacity[i] < capacity[idx])) idx = i;
    }
    return idx;
  }
};
