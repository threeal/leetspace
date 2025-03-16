#include <cmath>
#include <vector>

class Solution {
 public:
  long long repairCars(std::vector<int>& ranks, int cars) {
    long long low{100}, high{1};
    for (const auto rank : ranks) {
      if (rank < low) low = rank;
      if (rank > high) high = rank;
    }

    high *= cars;
    high *= cars;

    while (low < high) {
      const long long mid{low + (high - low) / 2};

      long long count{0};
      for (const auto rank : ranks) {
        count += static_cast<long long>(std::sqrt(mid / rank));
      }

      if (count < cars) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
