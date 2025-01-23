class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    return list1->val < list2->val ? list1 : list2;
  }
};
