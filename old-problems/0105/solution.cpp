#include <vector>

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return new TreeNode(preorder.size() + inorder.size());
  }
};
