#include <string>

using namespace std;

#include "solution.cpp"

int solution_cpp(const string& haystack, const string& needle) {
  return Solution().strStr(haystack, needle);
}
