#include <utility>

class Solution {
 public:
  int tribonacci(int n) {
    switch (n) {
      case 0:
        return 0;
      case 1:
        return 1;
      case 2:
        return 1;
    }

    int t[3]{0, 1, 1};
    while (--n >= 2) {
      t[0] += t[1] + t[2];
      std::swap(t[0], t[1]);
      std::swap(t[1], t[2]);
    }

    return t[2];
  }
};
