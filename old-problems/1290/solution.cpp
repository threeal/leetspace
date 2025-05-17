class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    int num{0};
    while (head != nullptr) {
      num <<= 1;
      if (head->val != 0) num |= 1;
      head = head->next;
    }
    return num;
  }
};
