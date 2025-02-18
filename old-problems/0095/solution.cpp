#include <vector>

class Solution {
 public:
  std::vector<TreeNode*> generateTrees(int n) {
    return std::vector<TreeNode*>(n, nullptr);
  }
};
