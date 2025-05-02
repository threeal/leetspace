#include <queue>

class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    std::queue<TreeNode*> queue{};
    queue.push(root);

    int sum{0};
    while (!queue.empty()) {
      sum = 0;
      for (std::size_t n{queue.size()}; n > 0; --n) {
        sum += queue.front()->val;

        if (queue.front()->left != nullptr) {
          queue.push(queue.front()->left);
        }

        if (queue.front()->right != nullptr) {
          queue.push(queue.front()->right);
        }

        queue.pop();
      }
    }

    return sum;
  }
};
