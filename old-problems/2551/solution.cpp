#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  long long putMarbles(std::vector<int>& weights, int k) {
    for (std::size_t i{1}; i < weights.size(); ++i) {
      weights[i - 1] += weights[i];
    }

    weights.pop_back();
    std::sort(weights.begin(), weights.end());

    return std::accumulate(weights.end() - k + 1, weights.end(), 0ll) -
        std::accumulate(weights.begin(), weights.begin() + k - 1, 0ll);
  }
};
