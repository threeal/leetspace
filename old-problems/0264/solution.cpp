#include <queue>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> nums{};
    nums.push(1);

    while (--n > 0) {
      const auto num = nums.top();
      nums.push(num * 2);
      nums.push(num * 3);
      nums.push(num * 5);
      while (nums.top() == num) nums.pop();
    }

    return nums.top();
  }
};
