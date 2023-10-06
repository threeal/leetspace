#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
string solution_cpp(const string& s) {
  Solution solution;
  return solution.reverseWords(s);
}
