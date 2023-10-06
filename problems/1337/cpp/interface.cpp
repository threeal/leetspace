#include <interface.hpp>
#include <map>
#include <set>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
vector<int> solution_cpp(const vector<vector<int>>& mat, const int& k) {
  auto mat_copy = mat;
  return Solution().kWeakestRows(mat_copy, k);
}
