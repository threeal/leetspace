#include <vector>

class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    std::vector<TreeNode*> nodes(count(root));

    TreeNode** it{nodes.data()};
    fill(it, root);

    return balance(nodes.data(), nodes.size());
  }

  int count(TreeNode* node) {
    return node != nullptr ? 1 + count(node->left) + count(node->right) : 0;
  }

  void fill(TreeNode**& it, TreeNode* node) {
    if (node->left != nullptr) fill(it, node->left);
    *it = node;
    ++it;
    if (node->right != nullptr) fill(it, node->right);
  }

  TreeNode* balance(TreeNode** data, std::size_t size) {
    switch (size) {
      case 0:
        return nullptr;

      case 1: {
        TreeNode* node{data[0]};
        node->left = nullptr;
        node->right = nullptr;
        return node;
      }
    }

    const std::size_t mid{size / 2};
    TreeNode* node{data[mid]};

    node->left = balance(data, mid);
    node->right = balance(data + mid + 1, size - mid - 1);

    return node;
  }
};
