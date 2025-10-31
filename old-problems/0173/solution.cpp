#include <stack>

class BSTIterator {
 private:
  std::stack<TreeNode*> nodes{};

 public:
  BSTIterator(TreeNode* root) : nodes{} {
    while (root != nullptr) {
      nodes.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode* node{nodes.top()};
    nodes.pop();

    const int val{node->val};

    node = node->right;
    while (node != nullptr) {
      nodes.push(node);
      node = node->left;
    }

    return val;
  }

  bool hasNext() {
    return !nodes.empty();
  }
};
