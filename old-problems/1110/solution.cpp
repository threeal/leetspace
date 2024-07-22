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
    collectTrees(trees, &root, deleteList);
    if (root != nullptr) trees.push_back(root);

    return trees;
  }

  void collectTrees(
      std::vector<TreeNode*>& trees,
      TreeNode** node,
      std::unordered_set<int>& deleteList) {
    if (deleteList.contains((*node)->val)) {
      if ((*node)->right != nullptr) {
        collectTrees(trees, &((*node)->right), deleteList);
        if (((*node)->right) != nullptr) trees.push_back(((*node)->right));
      }

      if ((*node)->left != nullptr) {
        collectTrees(trees, &((*node)->left), deleteList);
        if (((*node)->left) != nullptr) trees.push_back(((*node)->left));
      }

      *node = nullptr;
    } else {
      if ((*node)->right != nullptr) {
        collectTrees(trees, &((*node)->right), deleteList);
      }

      if ((*node)->left != nullptr) {
        collectTrees(trees, &((*node)->left), deleteList);
      }
    }
  }
};
