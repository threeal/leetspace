#include <interface.hpp>

extern "C" {
int sum(int num1, int num2);
}

template <>
int solution_c(const int& num1, const int& num2) {
  return sum(num1, num2);
}
