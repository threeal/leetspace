#include <internal.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
string solution_cpp(const string& s) {
  return Solution().longestPalindrome(s);
}
