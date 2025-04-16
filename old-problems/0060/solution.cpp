#include <cstdint>
#include <string>

class Solution {
 public:
  std::string getPermutation(int n, int k) {
    std::string permutation(n, '0');

    int factorial{1};
    for (int i{2}; i <= n; ++i) factorial *= i;

    std::uint16_t exists{0};
    for (int i{0}; i < n; ++i) {
      factorial /= n - i;
      for (int j{1}; j <= 9; ++j) {
        if ((exists & (1 << j)) == 0) {
          if (k <= factorial) {
            exists |= 1 << j;
            permutation[i] += j;
            break;
          } else {
            k -= factorial;
          }
        }
      }
    }

    return permutation;
  }
};
