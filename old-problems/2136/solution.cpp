#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int earliestFullBloom(
      std::vector<int>& plantTime, std::vector<int>& growTime) {
    std::vector<std::size_t> indices(plantTime.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(
        indices.begin(), indices.end(),
        [&](std::size_t i, std::size_t j) {
          return growTime[i] > growTime[j];
        });

    int day{0};
    int maxBloomDay{0};
    for (std::size_t i : indices) {
      day += plantTime[i];
      if (day + growTime[i] > maxBloomDay) {
        maxBloomDay = day + growTime[i];
      }
    }

    return maxBloomDay;
  }
};
