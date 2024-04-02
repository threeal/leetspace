class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    auto mid = head;
    auto fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      mid = mid->next;
      fast = fast->next->next;
    }

    auto prev = mid;
    auto it = mid->next;
    mid->next = nullptr;
    while (it != nullptr) {
      std::swap(prev, it->next);
      std::swap(prev, it);
    }

    auto tail = prev;
    while (head != nullptr && tail != nullptr) {
      if (head->val != tail->val) return false;
      head = head->next;
      tail = tail->next;
    }

    return true;
  }
};
