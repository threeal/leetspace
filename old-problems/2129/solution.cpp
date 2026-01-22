#include <string>

class Solution {
 public:
  std::string capitalizeTitle(std::string title) {
    for (std::size_t r{0}; r < title.size(); ++r) {
      const std::size_t l{r++};
      while (r < title.size() && title[r] != ' ') {
        if (title[r] < 'a') title[r] += 'a' - 'A';
        ++r;
      }

      if (r - l > 2) {
        if (title[l] >= 'a') title[l] -= 'a' - 'A';
      } else {
        if (title[l] < 'a') title[l] += 'a' - 'A';
      }
    }
    return title;
  }
};
