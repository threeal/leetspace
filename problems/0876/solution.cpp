class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto middle = head;

    while (head != nullptr && head->next != nullptr) {
      head = head->next->next;
      middle = middle->next;
    }

    return middle;
  }
};
