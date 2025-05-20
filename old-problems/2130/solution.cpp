class Solution {
 public:
  int pairSum(ListNode* head) {
    ListNode* fast{head};
    ListNode* prev{nullptr};
    ListNode* slow{head};
    while (fast != nullptr) {
      fast = fast->next->next;
      ListNode* next{slow->next};
      slow->next = prev;
      prev = slow;
      slow = next;
    }

    int maxSum{0};
    while (slow != nullptr) {
      if (prev->val + slow->val > maxSum) {
        maxSum = prev->val + slow->val;
      }
      prev = prev->next;
      slow = slow->next;
    }

    return maxSum;
  }
};
