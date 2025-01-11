#include <vector>

class Solution {
 public:
  int maxChunksToSorted(std::vector<int>& arr) {
    int chunks{0}, max{0};
    for (int i{0}; i < static_cast<int>(arr.size()); ++i) {
      if (arr[i] > max) max = arr[i];
      if (max == i) ++chunks;
    }
    return chunks;
  }
};
