#include <vector>

class Solution {
 public:
  double calculateTax(std::vector<std::vector<int>>& brackets, int income) {
    return brackets.size() + income;
  }
};
