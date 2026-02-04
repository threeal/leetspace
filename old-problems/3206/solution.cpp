#include <vector>

class Solution {
 public:
  int numberOfAlternatingGroups(std::vector<int>& colors) {
    int count{0};

    if (colors[0] != colors[colors.size() - 1] &&
        colors[0] == colors[colors.size() - 2]) ++count;

    if (colors[1] != colors[0] && colors[1] == colors[colors.size() - 1]) ++count;

    for (std::size_t i{2}; i < colors.size(); ++i) {
      if (colors[i] != colors[i - 1] && colors[i] == colors[i - 2]) ++count;
    }

    return count;
  }
};
