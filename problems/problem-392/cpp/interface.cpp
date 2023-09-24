#include <string>

using namespace std;

#include "solution.cpp"

bool solution_cpp(string s, string t) {
  return Solution().isSubsequence(s, t);
}
