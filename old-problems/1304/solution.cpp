#include <vector>

class Solution {
 public:
  std::vector<int> sumZero(int n) {
    std::vector<int> arr{};
    arr.reserve(n);

    for (int i{n / 2}; i > 0; --i) {
      arr.push_back(i);
      arr.push_back(-i);
    }

    if (n % 2 != 0) arr.push_back(0);

    return arr;
  }
};
