class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode** node = &head;
    while (*node != nullptr) {
      if ((*node)->val == val) {
        *node = (*node)->next;
      } else {
        node = &(*node)->next;
      }
    }
    return head;
  }
};
