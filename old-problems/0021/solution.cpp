class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* output{nullptr};
    ListNode** it{&output};

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        *it = list1;
        list1 = list1->next;
      } else {
        *it = list2;
        list2 = list2->next;
      }
      it = &((*it)->next);
    }

    if (list1 != nullptr) *it = list1;
    if (list2 != nullptr) *it = list2;

    return output;
  }
};
