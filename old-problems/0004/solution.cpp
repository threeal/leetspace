#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {
    std::size_t target{(a.size() + b.size()) / 2 + 1};
    if ((a.size() + b.size()) % 2 == 0) {
      std::size_t ai{0}, bi{0};
      int median1{}, median2{};
      while (target > 0) {
        if (ai == a.size()) {
          median2 = (target == 1) ? median1 : b[bi + target - 2];
          median1 = b[bi + target - 1];
          break;
        }

        if (bi == b.size()) {
          median2 = (target == 1) ? median1 : a[ai + target - 2];
          median1 = a[ai + target - 1];
          break;
        }

        median2 = median1;
        if (a[ai] <= b[bi]) {
          median1 = a[ai];
          ++ai;
        } else {
          median1 = b[bi];
          ++bi;
        }

        --target;
      }
      return (median1 + median2) / 2.0;
    } else {
      std::size_t ai{0}, bi{0};
      int median{};
      while (target > 0) {
        if (ai == a.size()) {
          median = b[bi + target - 1];
          break;
        }

        if (bi == b.size()) {
          median = a[ai + target - 1];
          break;
        }

        if (a[ai] <= b[bi]) {
          median = a[ai];
          ++ai;
        } else {
          median = b[bi];
          ++bi;
        }

        --target;
      }

      return median;
    }
  }
};
