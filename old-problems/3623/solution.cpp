#include <vector>

class Solution {
 public:
  int countTrapezoids(std::vector<std::vector<int>>& points) {
    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
      return a[1] < b[1];
    });

    std::vector<std::size_t> combinations{};
    std::size_t l{0}, r{1};
    while (r < points.size()) {
      if (points[l][1] != points[r][1]) {
        const std::size_t combination{(r - l) * (r - l - 1) / 2};
        if (combination > 0) combinations.push_back(combination);
        l = r;
      }
      ++r;
    }

    const std::size_t combination{(r - l) * (r - l - 1) / 2};
    if (combination > 0) combinations.push_back(combination);

    std::size_t prevCombinations{0}, count{0};
    for (const std::size_t combination : combinations) {
      count = (count + combination * prevCombinations) % 1000000007;
      prevCombinations += combination;
    }

    return count;
  }
};
