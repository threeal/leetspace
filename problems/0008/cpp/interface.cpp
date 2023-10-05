#include <internal.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const string& s) {
  return Solution().myAtoi(s);
}
