#include <vector>

class Solution {
 public:
  double calculateTax(std::vector<std::vector<int>>& brackets, int income) {
    double tax{0};

    if (income > 0) {
      if (income <= brackets[0][0]) {
        tax += static_cast<double>(income) * brackets[0][1] / 100;
      } else {
        tax += static_cast<double>(brackets[0][0]) * brackets[0][1] / 100;

        std::size_t i{1};
        while (brackets[i][0] < income) {
          tax += static_cast<double>(brackets[i][0] - brackets[i - 1][0]) *
              brackets[i][1] / 100;
          ++i;
        }

        tax += static_cast<double>(income - brackets[i - 1][0]) *
            brackets[i][1] / 100;
      }
    }

    return tax;
  }
};
