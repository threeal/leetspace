class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int excess{0};
    ListNode* i1{l1};
    ListNode* i2{l2};
    while (i1->next != nullptr && i2->next != nullptr) {
      i1->val += excess + i2->val;
      excess = i1->val / 10;
      i1->val %= 10;
      i1 = i1->next;
      i2 = i2->next;
    }

    i1->val += excess + i2->val;
    excess = i1->val / 10;
    i1->val %= 10;

    if (i2->next != nullptr) i1->next = i2->next;
    if (i1->next != nullptr && excess > 0) {
      i1 = i1->next;
      while (i1->next != nullptr && excess > 0) {
        i1->val += excess;
        excess = i1->val / 10;
        i1->val %= 10;
        i1 = i1->next;
      }

      i1->val += excess;
      excess = i1->val / 10;
      i1->val %= 10;
    }

    if (excess > 0) {
      i1->next = new ListNode(excess);
    }

    return l1;
  }
};
