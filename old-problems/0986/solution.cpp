#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& firstList,
      std::vector<std::vector<int>>& secondList) {
    std::vector<std::vector<int>> intersections{};

    std::size_t fi{0}, si{0};
    while (fi < firstList.size() && si < secondList.size()) {
      const int fl{firstList[fi][0]}, fr{firstList[fi][1]};
      const int sl{secondList[si][0]}, sr{secondList[si][1]};

      if (fl <= sl) {
        if (sl <= fr) {
          if (sr <= fr) {
            intersections.push_back({sl, sr});
            firstList[fi][0] = sr;
            ++si;
          } else {
            intersections.push_back({sl, fr});
            secondList[si][0] = fr;
            ++fi;
          }
        } else {
          ++fi;
        }
      } else {
        if (fl <= sr) {
          if (fr <= sr) {
            intersections.push_back({fl, fr});
            secondList[si][0] = fr;
            ++fi;
          } else {
            intersections.push_back({fl, sr});
            firstList[fi][0] = sr;
            ++si;
          }
        } else {
          ++si;
        }
      }
    }

    return intersections;
  }
};
