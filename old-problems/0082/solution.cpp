class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode** node{&head};
    while (*node != nullptr) {
      if ((*node)->next != nullptr && (*node)->val == (*node)->next->val) {
        const int val{(*node)->val};
        while (*node != nullptr && (*node)->val == val) {
          *node = (*node)->next;
        }
      } else {
        node = &((*node)->next);
      }
    }
    return head;
  }
};
