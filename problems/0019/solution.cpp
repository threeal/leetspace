class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto tail = head;
    while (n > 0) {
      tail = tail->next;
      --n;
    }

    if (tail == nullptr) {
      return head->next;
    }

    auto node = head;
    while (tail->next != nullptr) {
      node = node->next;
      tail = tail->next;
    }
    node->next = node->next->next;
    return head;
  }
};
