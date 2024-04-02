class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      std::swap(prev, head->next);
      std::swap(prev, head);
    }
    return prev;
  }
};
