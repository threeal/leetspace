#include <interface.hpp>
#include <string>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<string> solution_cpp(const string& digits) {
  Solution solution;
  return solution.letterCombinations(digits);
}
