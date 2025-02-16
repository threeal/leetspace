#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
    std::stack<int> stack{};
    for (std::size_t i{heights.size()}; i > 0; --i) {
      int count{0};
      while (!stack.empty() && stack.top() <= heights[i - 1]) {
        ++count;
        stack.pop();
      }
      if (!stack.empty()) ++count;
      stack.push(heights[i - 1]);
      heights[i - 1] = count;
    }
    return heights;
  }
};
