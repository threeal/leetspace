class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head->next == nullptr) return;

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

    it = prev;
    auto next = head->next;
    head->next = prev;
    while (it != next) {
      std::swap(next, it->next);
      it = it->next;
    }
  }
};
