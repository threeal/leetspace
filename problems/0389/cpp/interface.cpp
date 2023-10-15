#include <string>

using namespace std;

#include "solution.cpp"

string solution_cpp(string s, string t) {
  const auto c = Solution().findTheDifference(s, t);
  return {c};
}
