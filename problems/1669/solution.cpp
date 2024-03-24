class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    b -= a;

    auto la = list1;
    while (a > 1) {
      la = la->next;
      --a;
    }

    auto lb = la->next;
    while (b > 0) {
      lb = lb->next;
      --b;
    }

    la->next = list2;

    while (list2->next != nullptr) {
      list2 = list2->next;
    }
    list2->next = lb->next;

    return list1;
  }
};
