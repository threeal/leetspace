#include <vector>

class Solution {
 public:
  std::vector<int> findPeaks(std::vector<int>& mountain) {
    std::size_t n{0};
    for (std::size_t i{2}; i < mountain.size(); ++i) {
      if (mountain[i - 2] < mountain[i - 1] && mountain[i - 1] > mountain[i]) {
        mountain[n++] = i - 1;
      }
    }
    mountain.resize(n);
    return mountain;
  }
};
