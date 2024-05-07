#include <utility>

class Solution {
 public:
  ListNode* doubleIt(ListNode* head) {
    auto it = head->next;
    head->next = nullptr;
    while (it != nullptr) {
      std::swap(it->next, head);
      std::swap(it, head);
    }

    it = head;
    int mod = 0;
    while (it != nullptr) {
      const int val = mod + it->val * 2;
      mod = val / 10;
      it->val = val % 10;
      it = it->next;
    }

    it = head->next;
    head->next = nullptr;
    while (it != nullptr) {
      std::swap(it->next, head);
      std::swap(it, head);
    }

    return mod > 0 ? new ListNode(mod, head) : head;
  }
};
