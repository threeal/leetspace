#include <string>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<string> solution_cpp(string digits) {
  return Solution().letterCombinations(digits);
}
