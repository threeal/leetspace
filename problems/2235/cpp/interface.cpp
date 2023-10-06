#include <interface.hpp>

#include "solution.cpp"

template <>
int solution_cpp(const int& num1, const int& num2) {
  return Solution().sum(num1, num2);
}
