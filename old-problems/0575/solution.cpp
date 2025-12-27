#include <algorithm>
#include <vector>

class Solution {
 public:
  int distributeCandies(std::vector<int>& candyType) {
    if (candyType.size() == 2) return 1;

    std::sort(candyType.begin(), candyType.end());

    std::size_t uniques{1};
    const std::size_t half{candyType.size() / 2};

    for (std::size_t i{1}; i < candyType.size(); ++i) {
      if (candyType[i] != candyType[i - 1]) {
        ++uniques;
        if (uniques == half) break;
      }
    }

    return uniques;
  }
};
