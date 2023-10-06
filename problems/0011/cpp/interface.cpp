#include <interface.hpp>
#include <vector>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const vector<int>& height) {
  auto height_copy = height;
  return Solution().maxArea(height_copy);
}
