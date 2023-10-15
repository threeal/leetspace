#include <string>

using namespace std;

#include "solution.cpp"

string solution_cpp(string s, int k) {
  return Solution().decodeAtIndex(s, k);
}
