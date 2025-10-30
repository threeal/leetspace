#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> successfulPairs(
      std::vector<int>& spells, std::vector<int>& potions, long long success) {
    std::sort(potions.begin(), potions.end());

    std::vector<int> output(spells.size());
    for (std::size_t i{0}; i < spells.size(); ++i) {
      const long long spell = spells[i];

      std::size_t low{0}, high{potions.size() - 1};
      while (low < high) {
        const std::size_t mid{low + (high - low) / 2};
        if (spell * potions[mid] < success) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }

      output[i] = spell * potions[low] >= success
          ? potions.size() - low
          : 0;
    }

    return output;
  }
};
