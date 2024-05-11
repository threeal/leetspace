#include <cstring>

class Solution {
 public:
  void deleteNode(ListNode* node) {
    std::memcpy(node, node->next, sizeof(ListNode));
  }
};
