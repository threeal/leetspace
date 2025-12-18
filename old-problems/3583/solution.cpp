#include <unordered_map>
#include <vector>

class Solution {
 public:
  int specialTriplets(std::vector<int>& nums) {
    std::unordered_map<int, long long> rFreqs{};
    for (const int num : nums) ++rFreqs[num];

    long long triplets{0};
    std::unordered_map<int, long long> lFreqs{};
    for (const int num : nums) {
      --rFreqs[num];

      const auto lIt = lFreqs.find(2 * num);
      if (lIt != lFreqs.end()) {
        const auto rIt = rFreqs.find(2 * num);
        if (rIt != rFreqs.end()) {
          triplets = (triplets + (lIt->second * rIt->second)) % 1000000007;
        }
      }

      ++lFreqs[num];
    }

    return triplets;
  }
};
