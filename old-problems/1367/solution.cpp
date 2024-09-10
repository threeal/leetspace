class Solution {
 public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (head->val == root->val && checkSubPath(head, root)) return true;
    if (root->left != nullptr && isSubPath(head, root->left)) return true;
    if (root->right != nullptr && isSubPath(head, root->right)) return true;
    return false;
  }

  bool checkSubPath(ListNode* head, TreeNode* root) {
    if (head->next == nullptr) return true;
    if (root->left != nullptr && head->next->val == root->left->val) {
      if (checkSubPath(head->next, root->left)) return true;
    }
    if (root->right != nullptr && head->next->val == root->right->val) {
      if (checkSubPath(head->next, root->right)) return true;
    }
    return false;
  }
};
