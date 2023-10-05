#include <interface.hpp>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const string& s) {
  return Solution().firstUniqChar(s);
}
