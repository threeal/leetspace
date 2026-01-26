#include <vector>

extern "C" {
int totalNumbers(int* digits, int digitsSize);
}

int solution_c(std::vector<int> digits) {
  return totalNumbers(digits.data(), digits.size());
}
