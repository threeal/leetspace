class Solution {
 public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    return head->val == root->val;
  }
};
