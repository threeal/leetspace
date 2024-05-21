class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode** node{&head};
    while (*node != nullptr && (*node)->next != nullptr) {
      ListNode* temp{(*node)->next->next};
      (*node)->next->next = (*node);
      *node = (*node)->next;
      (*node)->next->next = temp;
      node = (&(*node)->next->next);
    }

    return head;
  }
};
