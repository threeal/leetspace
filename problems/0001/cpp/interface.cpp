#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(vector<int>& nums, int target) {
  return Solution().twoSum(nums, target);
}
