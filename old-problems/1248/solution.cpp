#include <vector>

class Solution {
 public:
  int numberOfSubarrays(std::vector<int>& nums, int k) {
    std::vector<int> evens(k);
    int evensIndex{k - 1};

    int right = nums.size();
    int left{right - 1};
    while (left >= 0 && evensIndex >= 0) {
      if (nums[left] % 2 != 0) {
        evens[evensIndex] = right - left;
        --evensIndex;
        right = left;
      }
      --left;
    }

    if (evensIndex >= 0) return 0;
    evensIndex += k;

    int totalCount{0};
    while (left >= 0) {
      if (nums[left] % 2 != 0) {
        totalCount += (right - left) * evens[evensIndex];
        evens[evensIndex] = right - left;
        if (--evensIndex < 0) evensIndex += k;
        right = left;
      }
      --left;
    }

    return totalCount + (right - left) * evens[evensIndex];
  }
};
