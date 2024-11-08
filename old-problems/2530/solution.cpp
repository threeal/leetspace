#include <queue>
#include <vector>

class Solution {
 public:
  long long maxKelements(std::vector<int>& nums, int k) {
    long long sum{0};
    std::priority_queue<int> maxs(nums.begin(), nums.end());
    while (k > 0) {
      const int max{maxs.top()};
      maxs.pop();

      sum += max;
      maxs.push(max % 3 == 0 ? max / 3 : max / 3 + 1);
      --k;
    }
    return sum;
  }
};
