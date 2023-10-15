#include <vector>

using namespace std;

#include "solution.cpp"

std::vector<int> solution_cpp(vector<int> nums, int target) {
  return Solution().searchRange(nums, target);
}
