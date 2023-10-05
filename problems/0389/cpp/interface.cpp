#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
char solution_cpp(const string& s, const string& t) {
  return Solution().findTheDifference(s, t);
}
