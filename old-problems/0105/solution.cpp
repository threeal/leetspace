#include <unordered_map>
#include <vector>

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, std::size_t> inorderPosOf{};
    for (std::size_t i{0}; i < inorder.size(); ++i) {
      inorderPosOf[inorder[i]] = i;
    }

    std::size_t i{0};
    return build(preorder, i, inorderPosOf, 0, inorder.size() - 1);
  }

 private:
  static TreeNode* build(
      const std::vector<int>& preorder, std::size_t& i,
      const std::unordered_map<int, std::size_t>& inorderPosOf,
      std::size_t l, std::size_t r) {
    TreeNode* node{new TreeNode(preorder[i])};
    const std::size_t mid{inorderPosOf.find(preorder[i])->second};

    ++i;
    if (l < mid) node->left = build(preorder, i, inorderPosOf, l, mid - 1);
    if (mid < r) node->right = build(preorder, i, inorderPosOf, mid + 1, r);

    return node;
  }
};
