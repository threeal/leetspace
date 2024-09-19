#include <unordered_set>
#include <utility>

class Solution {
 public:
  bool isHappy(int n) {
    std::unordered_set<int> processed{};
    while (n != 1) {
      if (processed.contains(n)) return false;
      processed.insert(n);
      int res{0};
      while (n > 0) {
        res += (n % 10) * (n % 10);
        n /= 10;
      }
      n = res;
    }
    return true;
  }
};
