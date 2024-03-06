class Solution {
 public:
  bool hasCycle(ListNode *head) {
    auto node = head;
    while (node != nullptr) {
      if (node->next == head) return true;
      auto prevNode = node;
      node = node->next;
      prevNode->next = head;
    }
    return false;
  }
};
