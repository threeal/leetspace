#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
string solution_cpp(const string& s, const int& numRows) {
  return Solution().convert(s, numRows);
}
