#include <algorithm>
#include <string>

class Solution {
 public:
  int getMinSwaps(std::string num, int k) {
    std::string original{num};
    while (--k >= 0) {
      std::next_permutation(num.begin(), num.end());
    }

    int swaps{0};
    for (std::size_t i{0}; i < num.size(); ++i) {
      std::size_t j{i};
      while (original[j] != num[i]) ++j;
      swaps += j - i;
      while (j > i) {
        original[j] = original[j - 1];
        --j;
      }
    }

    return swaps;
  }
};
