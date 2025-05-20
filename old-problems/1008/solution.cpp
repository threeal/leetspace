#include <span>
#include <vector>

class Solution {
 public:
  TreeNode* bstFromPreorder(std::vector<int>& preorder) {
    return bstFromPreorderRange(preorder);
  }

 private:
  static TreeNode* bstFromPreorderRange(std::span<int> preorder) {
    TreeNode* node{new TreeNode(preorder[0])};

    std::size_t i{1};
    while (i < preorder.size() && preorder[i] < preorder[0]) ++i;

    if (i > 1) {
      node->left = bstFromPreorderRange(preorder.subspan(1, i - 1));
    }

    if (i < preorder.size()) {
      node->right =
          bstFromPreorderRange(preorder.subspan(i, preorder.size() - i));
    }

    return node;
  }
};
