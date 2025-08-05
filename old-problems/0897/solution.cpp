class Solution {
 private:
  TreeNode** tail;

 public:
  TreeNode* increasingBST(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode* head{nullptr};
    tail = &head;
    inOrderTraversal(root);
    return head;
  }

 private:
  void inOrderTraversal(TreeNode* node) {
    if (node->left != nullptr) inOrderTraversal(node->left);

    TreeNode* right{node->right};
    node->left = nullptr;
    node->right = nullptr;

    *tail = node;
    tail = &(node->right);

    if (right != nullptr) inOrderTraversal(right);
  }
};
