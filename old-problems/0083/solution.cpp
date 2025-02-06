class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* node = head;
    while (node != nullptr) {
      while (node->next != nullptr && node->val == node->next->val) {
        node->next = node->next->next;
      }
      node = node->next;
    }
    return head;
  }
};
