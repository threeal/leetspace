#include <utility>

class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    int a{0}, b{1};
    while (--n != 0) {
      a += b;
      std::swap(a, b);
    }
    return b;
  }
};
