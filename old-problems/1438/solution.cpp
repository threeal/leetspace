#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums, int limit) {
    int longest{0};

    std::vector<int> increasing(nums.size());
    int* increasingFront{increasing.data()};
    int* increasingBack{increasingFront - 1};

    std::vector<int> decreasing(nums.size());
    int* decreasingFront{decreasing.data()};
    int* decreasingBack{decreasingFront - 1};

    for (int left = nums.size() - 1, right = left; left >= 0; --left) {
      while (increasingBack >= increasingFront && *increasingBack > nums[left]) {
        --increasingBack;
      }
      *(++increasingBack) = nums[left];

      while (decreasingBack >= decreasingFront && *decreasingBack < nums[left]) {
        --decreasingBack;
      }
      *(++decreasingBack) = nums[left];

      while (*decreasingFront - *increasingFront > limit) {
        if (nums[right] == *increasingFront) ++increasingFront;
        if (nums[right] == *decreasingFront) ++decreasingFront;
        --right;
      }

      if (right - left + 1 > longest) longest = right - left + 1;
    }

    return longest;
  }
};
