#include <internal.hpp>
#include <list>

using namespace std;

#include "solution.cpp"

template <>
bool solution_cpp(const int& x) {
  return Solution().isPalindrome(x);
}
