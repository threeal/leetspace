#include <cstdlib>
#include <set>
#include <vector>

class Solution {
 public:
  long long continuousSubarrays(std::vector<int>& nums) {
    long long count{0};

    std::multiset<int> vals{};
    vals.insert(nums[0]);

    std::size_t l{0}, r{0};
    while (r < nums.size()) {
      if (std::abs(*vals.begin() - *vals.rbegin()) <= 2) {
        count += r + 1 - l;
        if (++r < nums.size()) {
          vals.insert(nums[r]);
        }
      } else {
        const auto it = vals.find(nums[l]);
        vals.erase(it);
        ++l;
      }
    }

    return count;
  }
};
