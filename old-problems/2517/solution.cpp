#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumTastiness(std::vector<int>& price, int k) {
    std::sort(price.begin(), price.end());

    int low{0}, high{price.back() - price.front()};
    while (low < high) {
      const int mid{high - (high - low) / 2};

      int kk{1};
      std::size_t i{0};
      while (kk < k) {
        std::size_t j{i + 1};
        while (j < price.size() && price[j] - price[i] < mid) ++j;
        if (j == price.size()) break;
        i = j;
        ++kk;
      }

      if (kk == k) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
