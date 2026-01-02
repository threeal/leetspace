class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    head->val = k;
    return head;
  }
};
