#include <cstdint>
#include <vector>

class Solution {
 public:
  int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
    const int n = n;

    std::vector<std::uint32_t> bytes1(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (img1[i][j] == 0) continue;
        bytes1[i] |= 1 << j;
      }
    }

    std::vector<std::uint32_t> bytes2(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (img2[i][j] == 0) continue;
        bytes2[i] |= 1 << j;
      }
    }

    for (int i = n - 1; i >= 0; --i) {

    }

    return 0;
  }
};
