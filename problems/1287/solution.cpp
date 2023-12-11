#include <vector>

class Solution {
 public:
  int findSpecialInteger(std::vector<int>& arr) {
    auto a = arr.begin();
    auto b = a + arr.size() / 4;
    while (b != arr.end()) {
      if (*a == *b) return *a;
      ++a;
      ++b;
    }
    return 0;
  }
};
