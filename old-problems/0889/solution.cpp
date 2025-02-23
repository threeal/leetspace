#include <vector>

class Solution {
 private:
  int* pre;
  int* post;

 public:
  TreeNode* constructFromPrePost(
      std::vector<int>& preorder, std::vector<int>& postorder) {
    pre = preorder.data();
    post = postorder.data();
    TreeNode* root{};
    construct(root);
    return root;
  }

 private:
  void construct(TreeNode*& node) {
    node = new TreeNode(*pre);
    ++pre;
    if (node->val != *post) {
      construct(node->left);
      if (node->val != *post) {
        construct(node->right);
      }
    }
    ++post;
  }
};
