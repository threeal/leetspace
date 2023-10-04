#include <internal.hpp>
#include <stack>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
double solution_cpp(const vector<int>& a, const vector<int>& b) {
  auto a_copy = a;
  auto b_copy = b;
  return Solution().findMedianSortedArrays(a_copy, b_copy);
}
