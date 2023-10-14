#include <string>

using namespace std;

#include "solution.cpp"

string solution_cpp(const string& s, const int& numRows) {
  return Solution().convert(s, numRows);
}
