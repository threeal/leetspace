#include <algorithm>

class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* left{head};
    while (k > 1) {
      left = left->next;
      --k;
    }

    ListNode* right{head};
    ListNode* tail{left};
    while (tail->next != nullptr) {
      right = right->next;
      tail = tail->next;
    }

    std::swap(left->val, right->val);

    return head;
  }
};
