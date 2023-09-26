#include <unordered_set>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(vector<int> nums) {
  const auto k = Solution().removeDuplicates(nums);
  nums.resize(k);
  return nums;
}
