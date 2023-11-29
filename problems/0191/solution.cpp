#include <cstdint>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    // See this: https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html#index-_005f_005fbuiltin_005fpopcount.
    return __builtin_popcount(n);
  }
};
