#include <interface.hpp>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "solution.cpp"

template <>
string solution_cpp(const string& s) {
  return Solution().smallestSubsequence(s);
}
