class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* headX{nullptr};
    ListNode** tail{&head};
    ListNode** tailX{&headX};
    for (ListNode* node(head); node != nullptr; node = node->next) {
      if (node->val < x) {
        *tail = node;
        tail = &(node->next);
      } else {
        *tailX = node;
        tailX = &(node->next);
      }
    }
    *tail = headX;
    *tailX = nullptr;
    return head;
  }
};
