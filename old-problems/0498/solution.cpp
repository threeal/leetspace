#include <vector>

class Solution {
 public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
    std::size_t m{mat.size()}, n{mat[0].size()}, i{0}, j{1};

    std::vector<int> arr{};
    arr.reserve(m * n);

    while (i < m + n) {
      std::size_t ii{i < m ? i : m - 1};
      std::size_t jj{i < m ? 0 : i - m + 1};

      while (ii > 0 && jj < n) {
        arr.push_back(mat[ii][jj]);
        --ii;
        ++jj;
      }

      if (jj < n) {
        arr.push_back(mat[ii][jj]);
      }

      i += 2;

      if (j < m + n) {
        std::size_t ii{j < n ? 0 : j - n + 1};
        std::size_t jj{j < n ? j : n - 1};

        while (ii < m && jj > 0) {
          arr.push_back(mat[ii][jj]);
          ++ii;
          --jj;
        }

        if (ii < m) {
          arr.push_back(mat[ii][jj]);
        }

        j += 2;
      }
    }

    return arr;
  }
};
