#include <algorithm>
#include <vector>

class Solution {
 public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    int left{1};
    int right{*std::max_element(piles.begin(), piles.end())};

    while (left < right) {
      const int mid = (left + right) / 2;

      int time{0};
      for (const auto pile : piles) {
        time += pile / mid;
        if (pile % mid > 0) ++time;
        if (time > h) break;
      }

      if (time > h) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
