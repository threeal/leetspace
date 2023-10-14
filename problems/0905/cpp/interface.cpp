#include <list>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(const vector<int>& nums) {
  auto nums_copy = nums;
  return Solution().sortArrayByParity(nums_copy);
}
