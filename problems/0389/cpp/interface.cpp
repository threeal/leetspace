#include <interface.hpp>
#include <string>

using namespace std;

#include "solution.cpp"

template <>
string solution_cpp(const string& s, const string& t) {
  const auto c = Solution().findTheDifference(s, t);
  return {c};
}
