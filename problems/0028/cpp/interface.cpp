#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const string& haystack, const string& needle) {
  return Solution().strStr(haystack, needle);
}
