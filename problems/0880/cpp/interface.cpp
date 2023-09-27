#include <stack>
#include <string>

using namespace std;

#include "solution.cpp"

string solution_cpp(const string& s, int k) {
  Solution solution;
  return solution.decodeAtIndex(s, k);
}
