#include <vector>

class Solution {
 public:
  int longestBalanced(std::vector<int>& nums) {
    int freqs[100001]{0};
    int evens{0}, odds{0};

    std::size_t l{0}, r{0}, maxLength{0};
    while (true) {
      while (r < nums.size()) {
        if (++freqs[nums[r]] == 1) {
          if (nums[r] % 2 == 0) {
            ++evens;
          } else {
            ++odds;
          }
        }

        if (evens == odds) {
          maxLength = r + 1 - l;
        }

        ++r;
      }

      if (--freqs[nums[l]] == 0) {
        if (nums[l] % 2 == 0) {
          --evens;
        } else {
          --odds;
        }
      }

      if (++l == nums.size()) break;

      while (r - l > maxLength) {
        --r;
        if (--freqs[nums[r]] == 0) {
          if (nums[r] % 2 == 0) {
            --evens;
          } else {
            --odds;
          }
        }
      }
    }

    return maxLength;
  }
};
