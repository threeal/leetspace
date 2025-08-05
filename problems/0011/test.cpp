// clang-format off
#include "solution.cpp"
// clang-format on

#include <cassert>
#include <vector>

int main() {
  {
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(Solution{}.maxArea(height) == 49);
  }

  {
    std::vector<int> height{1, 1};
    assert(Solution{}.maxArea(height) == 1);
  }
}
