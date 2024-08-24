#include <utility>
#include <vector>

class Solution {
 public:
  int commonFactors(int a, int b) {
    if (b < a) std::swap(a, b);

    int factors{1};
    for (int i{2}; i <= a; ++i) {
      if (a % i == 0 && b % i == 0) ++factors;
    }
    return factors;
  }
};
