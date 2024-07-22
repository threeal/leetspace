#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<TreeNode*> delNodes(
      TreeNode* root, std::vector<int>& to_delete) {
    std::unordered_set<int> deleteList{};
    for (const auto val : to_delete) {
      deleteList.insert(val);
    }

    std::vector<TreeNode*> trees{};
    const bool deleted = collectTrees(trees, root, deleteList);
    if (!deleted) trees.push_back(root);

    return trees;
  }

  bool collectTrees(
      std::vector<TreeNode*>& trees,
      TreeNode* node,
      std::unordered_set<int>& deleteList) {
    if (deleteList.contains(node->val)) {
      if (node->right != nullptr) {
        const bool deleted = collectTrees(trees, node->right, deleteList);
        if (!deleted) trees.push_back(node->right);
      }

      if (node->left != nullptr) {
        const bool deleted = collectTrees(trees, node->left, deleteList);
        if (!deleted) trees.push_back(node->left);
      }

      return true;
    } else {
      if (node->right != nullptr) {
        const bool deleted = collectTrees(trees, node->right, deleteList);
        if (deleted) node->right = nullptr;
      }

      if (node->left != nullptr) {
        const bool deleted = collectTrees(trees, node->left, deleteList);
        if (deleted) node->left = nullptr;
      }

      return false;
    }
  }
};
