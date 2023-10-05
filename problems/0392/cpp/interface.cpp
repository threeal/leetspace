#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
bool solution_cpp(const string& s, const string& t) {
  return Solution().isSubsequence(s, t);
}
