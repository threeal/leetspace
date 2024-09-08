#include <numeric>
#include <vector>

class Solution {
 public:
  int stoneGameVI(std::vector<int>& aliceValues, std::vector<int>& bobValues) {
    std::vector<int> indices(aliceValues.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
      return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
    });

    int alice{0};
    for (std::size_t i{0}; i < indices.size(); i += 2) {
      alice += aliceValues[indices[i]];
    }

    int bob{0};
    for (std::size_t i{1}; i < indices.size(); i += 2) {
      bob += bobValues[indices[i]];
    }

    return alice == bob ? 0 : (alice > bob ? 1 : -1);
  }
};
