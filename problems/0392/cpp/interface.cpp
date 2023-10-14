#include <string>

using namespace std;

#include "solution.cpp"

bool solution_cpp(const string& s, const string& t) {
  return Solution().isSubsequence(s, t);
}
