#include <utility>

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    auto end{head};
    for (int i{0}; i < k; ++i) {
      if (end == nullptr) return head;
      end = end->next;
    }

    auto it{head->next};
    head->next = reverseKGroup(end, k);
    for (int i{1}; i < k; ++i) {
      std::swap(it->next, head);
      std::swap(it, head);
    }

    return head;
  }
};
