class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* slow{head};
    ListNode* fast{head->next};
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* left{head};
    ListNode* right{slow->next};
    slow->next = nullptr;

    left = sortList(left);
    right = sortList(right);

    ListNode** tail{&head};
    while (left != nullptr && right != nullptr) {
      if (left->val <= right->val) {
        *tail = left;
        left = left->next;
      } else {
        *tail = right;
        right = right->next;
      }
      tail = &((*tail)->next);
    }
    *tail = left != nullptr ? left : right;

    return head;
  }
};
