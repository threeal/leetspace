#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> flipAndInvertImage(
      std::vector<std::vector<int>>& image) {
    for (std::vector<int>& row : image) {
      std::size_t l{0}, r{row.size() - 1};
      while (l < r) {
        if (row[l] == 0) {
          if (row[r] == 0) {
            row[l] = 1;
            row[r] = 1;
          }
        } else {
          if (row[r] != 0) {
            row[l] = 0;
            row[r] = 0;
          }
        }
        ++l, --r;
      }
      if (l == r) row[l] = row[l] == 0 ? 1 : 0;
    }
    return image;
  }
};
