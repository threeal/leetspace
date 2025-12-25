#include <numeric>
#include <set>
#include <vector>

class Solution {
 public:
  int countTrapezoids(std::vector<std::vector<int>>& points) {
    std::vector<std::vector<int>> gradients{};
    for (std::size_t i{0}; i < points.size(); ++i) {
      const int ii = i;

      for (std::size_t j{i +1}; j < points.size(); ++j) {
        const int jj = j;

        int my{points[i][0] - points[j][0]};
        int mx{points[i][1] - points[j][1]};

        if (my == 0) {
          gradients.push_back({0, 1, points[i][0], ii, jj});
        } else if (mx == 0) {
          gradients.push_back({1, 0, points[i][1], ii, jj});
        } else {
          if (my < 0) {
            my = -my;
            mx = -mx;
          }

          const int div{std::gcd(my, mx)};
          my /= div;
          mx /= div;

          const int axis{my * points[i][1] - mx * points[i][0]};
          gradients.push_back({my, mx, axis, ii, jj});
        }
      }
    }

    std::sort(gradients.begin(), gradients.end());

    std::set<std::vector<int>> combinations{};
    std::vector<int> combination(4);

    for (std::size_t i{0}; i < gradients.size(); ++i) {
      std::size_t j{i + 1};

      while (
          j < gradients.size() &&
          gradients[i][0] == gradients[j][0] &&
          gradients[i][1] == gradients[j][1] &&
          gradients[i][2] == gradients[j][2]) {
        ++j;
      }

      while (
          j < gradients.size() &&
          gradients[i][0] == gradients[j][0] &&
          gradients[i][1] == gradients[j][1] &&
          gradients[i][2] != gradients[j][2]) {
        combination[0] = gradients[i][3];
        combination[1] = gradients[i][4];
        combination[2] = gradients[j][3];
        combination[3] = gradients[j][4];

        std::sort(combination.begin(), combination.end());
        combinations.insert(combination);

        ++j;
      }
    }

    return combinations.size();
  }
};
