#include <vector>

class Solution {
 public:
  std::vector<TreeNode*> delNodes(
      TreeNode* root, std::vector<int>& /*to_delete*/) {
    return {root};
  }
};
