#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
    std::vector<int> indices(groupSizes);
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(
        indices.begin(), indices.end(),
        [&](std::size_t a, std::size_t b) {
          return groupSizes[a] < groupSizes[b];
        });

    std::vector<std::vector<int>> output{};

    std::size_t i{0};
    while (i < indices.size()) {
      const int groupSize{groupSizes[indices[i]]};
      output.push_back(std::vector<int>(groupSize));
      for (int j{0}; j < groupSize; ++j) {
        output.back()[j] = indices[i + j];
      }
      i += groupSize;
    }

    return output;
  }
};
