#include <limits>
#include <vector>

class Solution {
 public:
  long long maxPower(std::vector<int>& stations, int r, int k) {
    const std::size_t rr = r;

    long long startSum{0};
    for (int i{0}; i < r; ++i) startSum += stations[i];

    long long sum{startSum};
    long long low{std::numeric_limits<int>::max()};
    long long high{std::numeric_limits<int>::min()};
    for (std::size_t i{0}; i < stations.size(); ++i) {
      if (i + rr < stations.size()) sum += stations[i + rr];
      if (sum < low) low = sum;
      if (sum > high) high = sum;
      if (i >= rr) sum -= stations[i - rr];
    }
    high += k;

    std::vector<int> powers(stations.size());

    while (low < high) {
      const long long mid{high - (high - low) / 2};

      long long kk = k;
      long long sum{startSum};
      powers.assign(powers.size(), 0);

      bool valid{true};
      for (std::size_t i{0}; i < stations.size(); ++i) {
        if (i + rr < stations.size()) sum += stations[i + rr];

        if (sum < mid) {
          if (mid - sum <= kk) {
            powers[std::min(i + rr, stations.size() - 1)] = mid - sum;
            kk -= mid - sum;
            sum = mid;
          } else {
            valid = false;
            break;
          }
        }

        if (i >= rr) sum -= stations[i - rr] + powers[i - rr];
      }

      if (valid) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
