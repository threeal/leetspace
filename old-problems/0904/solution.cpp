#include <vector>

class Solution {
 public:
  int totalFruit(std::vector<int>& fruits) {
    std::size_t b{1};
    while (b < fruits.size() && fruits[b] == fruits[0]) ++b;
    if (b == fruits.size()) return b;

    std::size_t a{b - 1}, max{b + 1};
    for (std::size_t l{0}, r{b + 1}; r < fruits.size(); ++r) {
      if (fruits[r] == fruits[a]) {
        a = b;
        b = r;
        if (r + 1 - l > max) max = r + 1 - l;
      } else if (fruits[r] == fruits[b]) {
        b = r;
        if (r + 1 - l > max) max = r + 1 - l;
      } else {
        l = a + 1;
        a = b;
        b = r;
      }
    }

    return max;
  }
};
