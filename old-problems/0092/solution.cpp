class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode** lnode{&head};

    int i{1};
    while (i < left) {
      lnode = &((*lnode)->next);
      ++i;
    }

    ListNode** rnode{&((*lnode)->next)};
    while (++i <= right) {
      ListNode* temp{*lnode};
      *lnode = *rnode;
      *rnode = (*rnode)->next;
      (*lnode)->next = temp;
    }

    return head;
  }
};
