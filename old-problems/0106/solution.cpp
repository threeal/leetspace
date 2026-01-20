#include <vector>

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return new TreeNode(inorder.size() + postorder.size());
  }
};
