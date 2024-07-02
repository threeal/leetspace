#include <vector>

class Solution {
 public:
  int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
    int right = grumpy.size() - 1;
    int left = grumpy.size() - minutes;

    int satisfied{0};
    for (int i{right}; i >= left; --i) {
      satisfied += customers[i];
    }

    for (int i{left - 1}; i >= 0; --i) {
      if (!grumpy[i]) satisfied += customers[i];
    }

    int maxSatisfied{satisfied};
    while (--left >= 0) {
      if (grumpy[left]) satisfied += customers[left];
      if (grumpy[right]) satisfied -= customers[right];
      if (satisfied > maxSatisfied) maxSatisfied = satisfied;
      --right;
    }

    return maxSatisfied;
  }
};
