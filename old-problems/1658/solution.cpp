#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int x) {
    int res = -1;
    const int n = nums.size();

    int xx = x;

    int ll = 0;
    int rr = n - 1;

    while (ll < n) {
      xx -= nums[ll];
      if (xx <= 0) {
        if (xx == 0) {
          int new_res = ll + 1;
          res = res > 0 ? std::min(res, new_res) : new_res;
        }
        break;
      }
      ++ll;
    }

    if (ll == n) --ll;

    while (ll >= 0) {
      xx += nums[ll];
      --ll;
      while (xx < 0 && rr < n - 1) {
        xx += nums[rr];
        ++rr;
      }

      while (rr > ll && xx >= nums[rr]) {
        xx -= nums[rr];
        if (xx == 0) {
          int new_res = ll + 1 + n - rr;
          res = res > 0 ? std::min(res, new_res) : new_res;
        }
        --rr;
      }
    }

    return res;
  }
};
