#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
    const int observedTotal = std::accumulate(rolls.begin(), rolls.end(), 0);
    const int missingTotal = mean * (rolls.size() + n) - observedTotal;

    if (missingTotal < n || missingTotal > n * 6) return {};

    std::vector<int> out(n);
    std::fill(out.begin(), out.begin() + missingTotal % n, missingTotal / n + 1);
    std::fill(out.begin() + missingTotal % n, out.end(), missingTotal / n);

    return out;
  }
};
