#include <unordered_set>

class FindElements {
 private:
  std::unordered_set<int> exists;

 public:
  FindElements(TreeNode* root) {
    root->val = 0;
    traverse(root);
  }

  bool find(int target) {
    return exists.contains(target);
  }

 private:
  void traverse(TreeNode* node) {
    exists.insert(node->val);

    if (node->left != nullptr) {
      node->left->val = node->val * 2 + 1;
      traverse(node->left);
    }

    if (node->right != nullptr) {
      node->right->val = node->val * 2 + 2;
      traverse(node->right);
    }
  }
};
