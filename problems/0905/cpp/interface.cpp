#include <list>
#include <vector>

using namespace std;

#include "solution.cpp"

vector<int> solution_cpp(vector<int> nums) {
  return Solution().sortArrayByParity(nums);
}
