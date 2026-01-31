#include <unordered_map>
#include <vector>

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    std::unordered_map<int, std::size_t> postorderPosOf{};
    for (std::size_t i{0}; i < postorder.size(); ++i) {
      postorderPosOf[postorder[i]] = i;
    }

    std::size_t i{0};
    return build(inorder, i, postorderPosOf, 0, postorder.size() - 1, nullptr);
  }

 private:
  TreeNode* build(
      const std::vector<int>& inorder, std::size_t& i,
      const std::unordered_map<int, std::size_t>& postorderPosOf,
      std::size_t l, std::size_t r, TreeNode* leftChild) {
    TreeNode* node{new TreeNode(inorder[i])};
    node->left = leftChild;

    const std::size_t mid{postorderPosOf.find(inorder[i])->second};
    ++i;

    if (l < mid) {
      node->right = build(inorder, i, postorderPosOf, l, mid - 1, nullptr);
    }

    return mid < r
        ? build(inorder, i, postorderPosOf, mid + 1, r, node)
        : node;
  }
};
