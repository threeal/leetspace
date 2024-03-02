#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> outputs;
    outputs.reserve(nums.size());

    std::stack<int> negs;
    for (const auto num : nums) {
      const auto sqr = num * num;
      if (num < 0) {
        negs.push(sqr);
      } else {
        while (!negs.empty() && negs.top() < sqr) {
          outputs.push_back(negs.top());
          negs.pop();
        }
        outputs.push_back(sqr);
      }
    }

    while (!negs.empty()) {
      outputs.push_back(negs.top());
      negs.pop();
    }

    return outputs;
  }
};
