#include <string>

using namespace std;

#include "solution.cpp"

int solution_cpp(string haystack, string needle) {
  return Solution().strStr(haystack, needle);
}
