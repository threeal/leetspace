#include <tuple>

class Solution {
 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return std::get<1>(explore(root));
  }

 private:
  static std::tuple<int, TreeNode*> explore(TreeNode* node) {
    if (node->left != nullptr) {
      const auto [ldepth, lnode] = explore(node->left);
      if (node->right != nullptr) {
        const auto& [rdepth, rnode] = explore(node->right);
        if (ldepth == rdepth) {
          return {ldepth + 1, node};
        } else if (ldepth > rdepth) {
          return {ldepth + 1, lnode};
        } else {
          return {rdepth + 1, rnode};
        }
      } else {
        return {ldepth + 1, lnode};
      }
    } else {
      if (node->right != nullptr) {
        const auto [rdepth, rnode] = explore(node->right);
        return {rdepth + 1, rnode};
      } else {
        return {0, node};
      }
    }
  }
};
