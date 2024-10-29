#include <queue>

class Solution {
 public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>>
        largest{};

    std::queue<TreeNode*> nodes{};
    nodes.push(root);

    while (!nodes.empty()) {
      long long sum{0};
      for (std::size_t n{nodes.size()}; n > 0; --n) {
        if (nodes.front()->left != nullptr) nodes.push(nodes.front()->left);
        if (nodes.front()->right != nullptr) nodes.push(nodes.front()->right);

        sum += nodes.front()->val;
        nodes.pop();
      }

      largest.push(sum);
      if (static_cast<int>(largest.size()) > k) largest.pop();
    }

    return static_cast<int>(largest.size()) == k ? largest.top() : -1;
  }
};
