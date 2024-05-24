#include <utility>

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode** node{&head};
    while (*node != nullptr) {
      auto end{(*node)->next};
      for (int i{1}; i < k; ++i) {
        if (end == nullptr) return head;
        end = end->next;
      }

      auto it{(*node)->next};
      (*node)->next = end;
      for (int i{1}; i < k; ++i) {
        std::swap(it->next, *node);
        std::swap(it, *node);
      }

      for (int i{0}; i < k; ++i) {
        node = &((*node)->next);
      }
    }

    return head;
  }
};
