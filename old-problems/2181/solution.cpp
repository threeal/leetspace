class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    auto begin = head;
    auto it = begin->next;

    int sum{0};
    while (it != nullptr) {
      if (it->val == 0) {
        it->val = sum;
        begin->next = it;
        begin = it;
        sum = 0;
      } else {
        sum += it->val;
      }
      it = it->next;
    }

    return head->next;
  }
};
