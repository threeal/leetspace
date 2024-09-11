#include <vector>

class Solution {
 public:
  std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n{0};
    auto node = head;
    while (node != nullptr) {
      ++n;
      node = node->next;
    }

    std::vector<ListNode*> output(k);
    for (int i{0}; i < k; ++i) {
      output[i] = head;
      for (int j{n / k + (i < n % k ? 1 : 0)}; j > 1; --j) {
        head = head->next;
      }

      if (head != nullptr) {
        node = head;
        head = head->next;
        node->next = nullptr;
      }
    }

    return output;
  }
};
