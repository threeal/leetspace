#include <set>
#include <vector>

class Solution {
 public:
  long long minimumCost(std::vector<int>& nums, int k, int dist) {
    const std::size_t kk = k - 1;

    long long cost{0};
    std::multiset<int> negMins{}, maxs{};

    const std::size_t end = 2 + dist;
    for (std::size_t i{1}; i < end; ++i) {
      cost += nums[i];
      negMins.insert(-nums[i]);
      if (negMins.size() > kk) {
        const int maxMin{-*(negMins.begin())};
        cost -= maxMin;
        negMins.erase(negMins.begin());
        maxs.insert(maxMin);
      }
    }

    long long minCost{cost};
    for (std::size_t i{end}; i < nums.size(); ++i) {
      cost += nums[i];
      negMins.insert(-nums[i]);
      if (negMins.size() > kk) {
        const int maxMin{-*(negMins.begin())};
        cost -= maxMin;
        negMins.erase(negMins.begin());
        maxs.insert(maxMin);
      }

      if (cost < minCost) minCost = cost;
    }

    return nums[0] + minCost;
  }
};
