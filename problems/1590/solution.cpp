#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minSubarray(std::vector<int>& nums, int p) {
    const int targetMod = std::accumulate(nums.begin(), nums.end(), 0ll) % p;
    if (targetMod == 0) return 0;

    int mod{0};
    std::unordered_map<int, int> modIdxs;
    modIdxs[0] = -1;

    int minLength = nums.size();
    for (int i{0}; i < static_cast<int>(nums.size()); ++i) {
      mod = (mod + nums[i]) % p;

      const auto it = modIdxs.find((p + mod - targetMod) % p);
      if (it != modIdxs.end()) {
        if (i - it->second < minLength) minLength = i - it->second;
      }

      modIdxs[mod] = i;
    }

    return minLength == static_cast<int>(nums.size()) ? -1 : minLength;
  }
};
