#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
    for (std::vector<int>& domino : dominoes) {
      if (domino[0] > domino[1]) std::swap(domino[0], domino[1]);
    }

    std::sort(dominoes.begin(), dominoes.end());

    int totalPairs{0}, pairs{0};
    for (std::size_t i{1}; i < dominoes.size(); ++i) {
      if (dominoes[i][0] == dominoes[i - 1][0] &&
          dominoes[i][1] == dominoes[i - 1][1]) {
        ++pairs;
      } else {
        if (pairs > 0) totalPairs += (pairs * (pairs + 1)) / 2;
        pairs = 0;
      }
    }

    if (pairs > 0) totalPairs += (pairs * (pairs + 1)) / 2;
    return totalPairs;
  }
};
