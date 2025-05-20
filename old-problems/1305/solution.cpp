#include <vector>

class Solution {
 public:
  std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    return {root1->val, root2->val};
  }
};
