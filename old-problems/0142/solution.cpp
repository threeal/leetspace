class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow{head};
    ListNode* fast{head};
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        while (head != slow) {
          head = head->next;
          slow = slow->next;
        }
        return head;
      }
    }
    return nullptr;
  }
};
