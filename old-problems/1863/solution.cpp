#include <vector>

int pown(int x, int n) {
  int result{1};
  while (n) {
    if (n & 1) result *= x;
    x *= x;
    n >>= 1;
  }
  return result;
}

class Solution {
 public:
  int subsetXORSum(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int sum{0};

    std::vector<int> caches{};
    caches.reserve(pown(2, nums.size() - 1) - 1);

    for (int i = nums.size() - 1; i > 0; --i) {
      for (int j = caches.size() - 1; j >= 0; --j) {
        const auto val{caches[j] ^ nums[i]};
        sum += val;
        caches.push_back(val);
      }

      sum += nums[i];
      caches.push_back(nums[i]);
    }

    for (const auto cache : caches) {
      sum += cache ^ nums[0];
    }
    sum += nums[0];

    return sum;
  }
};
