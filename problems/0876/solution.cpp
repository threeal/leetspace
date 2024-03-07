class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto middle = head;

    while (head->next != nullptr) {
      head = head->next;
      middle = middle->next;
      if (head->next == nullptr) break;
      head = head->next;
    }

    return middle;
  }
};
