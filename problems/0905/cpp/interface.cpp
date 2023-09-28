#include <list>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(const vector<int>& nums) {
  Solution solution;
  auto nums_copy = nums;
  return solution.sortArrayByParity(nums_copy);
}
