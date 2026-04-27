#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxDistance(std::vector<int>& colors) {
    if (colors[0] != colors[colors.size() - 1]) return colors.size() - 1;

    std::size_t l{0}, r{colors.size() - 1};
    while (colors[l] == colors[0]) ++l;
    while (colors[r] == colors[0]) --r;

    return std::max(r, colors.size() - l - 1);
  }
};
