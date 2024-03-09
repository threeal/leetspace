class Solution {
 public:
  bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    // Iterate using two pointers at different speeds.
    // A linked list is considered to have a cycle if these two pointers ever meet.
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }

    return false;
  }
};
