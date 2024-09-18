#include <numeric>

class Solution {
 public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    auto node = head;
    while (node->next != nullptr) {
      node->next = new ListNode(
          std::gcd(node->val, node->next->val), node->next);
      node = node->next->next;
    }
    return head;
  }
};
