#include <vector>

class Solution {
 public:
  std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    // Find the first critical point.
    while (head->next->next != nullptr) {
      if ((head->val > head->next->val && head->next->val < head->next->next->val) ||
          (head->val < head->next->val && head->next->val > head->next->next->val)) {
        // Find the second critical point.
        int index{1};
        head = head->next;
        while (head->next->next != nullptr) {
          if ((head->val > head->next->val && head->next->val < head->next->next->val) ||
              (head->val < head->next->val && head->next->val > head->next->next->val)) {
            int min{index};
            int max{index};
            // Find the subsequent critical points.
            index = 1;
            head = head->next;
            while (head->next->next != nullptr) {
              if ((head->val > head->next->val && head->next->val < head->next->next->val) ||
                  (head->val < head->next->val && head->next->val > head->next->next->val)) {
                max += index;
                if (index < min) min = index;
                index = 0;
              }
              head = head->next;
              ++index;
            }
            return {min, max};
          }
          head = head->next;
          ++index;
        }
        return {-1, -1};
      }
      head = head->next;
    }
    return {-1, -1};
  }
};
