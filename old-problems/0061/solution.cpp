class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;

    int n{1};
    ListNode* tail{head};
    while (tail->next != nullptr) {
      tail = tail->next;
      ++n;
    }

    k %= n;
    if (k == 0) return head;

    ListNode* node{head};
    for (int i{n - k - 1}; i > 0; --i) {
      node = node->next;
    }

    ListNode* temp{node->next};
    node->next = nullptr;
    tail->next = head;
    return temp;
  }
};
