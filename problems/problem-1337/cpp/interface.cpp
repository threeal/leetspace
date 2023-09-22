#include <map>
#include <set>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(vector<vector<int>>& mat, int k) {
  return Solution().kWeakestRows(mat, k);
}
