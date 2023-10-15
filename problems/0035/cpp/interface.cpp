#include <vector>

using namespace std;

#include "solution.cpp"

int solution_cpp(vector<int> nums, int target) {
  return Solution().searchInsert(nums, target);
}
