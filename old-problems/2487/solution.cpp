#include <utility>

class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    auto it = head->next;
    head->next = nullptr;
    while (it != nullptr) {
      std::swap(it->next, head);
      std::swap(it, head);
    }

    it = head;
    while (it != nullptr && it->next != nullptr) {
      while (it->next != nullptr && it->next->val < it->val) {
        it->next = it->next->next;
      }
      it = it->next;
    }

    it = head->next;
    head->next = nullptr;
    while (it != nullptr) {
      std::swap(it->next, head);
      std::swap(it, head);
    }

    return head;
  }
};
