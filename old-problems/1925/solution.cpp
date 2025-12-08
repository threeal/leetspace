#include <vector>

class Solution {
 public:
  int countTriples(int n) {
    std::vector<int> squares(n);
    for (int i{0}; i < n; ++i) squares[i] = (i + 1) * (i + 1);

    int count{0};
    for (int a{1}; a <= n; ++a) {
      const int a2{a * a};
      for (int b{a + 1}; b <= n; ++b) {
        const int c2{a2 + b * b};
        const auto it = std::lower_bound(squares.begin(), squares.end(), c2);
        if (it != squares.end() && *it == c2) ++count;
      }
    }

    return count * 2;
  }
};
