#include <vector>

extern "C" {
double calculateTax(
    int** brackets, int bracketsSize, int* bracketsColSize, int income);
}

double solution_c(std::vector<std::vector<int>> brackets, int income) {
  std::vector<int*> bracketsDatas(brackets.size());
  std::vector<int> bracketsSizes(brackets.size());
  for (std::size_t i{0}; i < brackets.size(); ++i) {
    bracketsDatas[i] = brackets[i].data();
    bracketsSizes[i] = brackets[i].size();
  }

  return calculateTax(
      bracketsDatas.data(), brackets.size(), bracketsSizes.data(), income);
}
