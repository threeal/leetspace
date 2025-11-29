#include <vector>

class Solution {
 public:
  int shipWithinDays(std::vector<int>& weights, int days) {
    int low{1}, high{0};
    for (const int weight : weights) high += weight;

    while (low < high) {
      const int mid{low + (high - low) / 2};

      int count{1}, sum{0};
      for (const int weight : weights) {
        if (sum + weight > mid) {
          if (weight > mid || ++count > days) {
            count = days + 1;
            break;
          }
          sum = weight;
        } else {
          sum += weight;
        }
      }

      if (count > days) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
