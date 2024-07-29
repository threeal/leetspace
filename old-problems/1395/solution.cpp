#include <vector>

class Solution {
 public:
  int numTeams(std::vector<int>& rating) {
    std::vector<int> lessers(rating.size(), 0);
    std::vector<int> greaters(rating.size(), 0);

    int count{0};
    for (int i = rating.size() - 1; i > 0; --i) {
      for (int j{i - 1}; j >= 0; --j) {
        if (rating[i] > rating[j]) {
          count += greaters[i];
          ++greaters[j];
        } else {
          count += lessers[i];
          ++lessers[j];
        }
      }
    }

    return count;
  }
};
