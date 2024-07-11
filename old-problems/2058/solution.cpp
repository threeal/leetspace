#include <vector>

class Solution {
 public:
  std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int prevPrevVal{head->val};
    head = head->next;

    int prevVal{head->val};
    head = head->next;

    // Find the first critical point.
    while (head != nullptr) {
      if ((prevPrevVal > prevVal && prevVal < head->val) ||
          (prevPrevVal < prevVal && prevVal > head->val)) {
        // Find the second critical point.
        int index{1};
        prevPrevVal = prevVal;
        prevVal = head->val;
        head = head->next;
        while (head != nullptr) {
          if ((prevPrevVal > prevVal && prevVal < head->val) ||
              (prevPrevVal < prevVal && prevVal > head->val)) {
            int min{index};
            int max{index};

            // Find the subsequent critical points.
            index = 1;
            prevPrevVal = prevVal;
            prevVal = head->val;
            head = head->next;
            while (head != nullptr) {
              if ((prevPrevVal > prevVal && prevVal < head->val) ||
                  (prevPrevVal < prevVal && prevVal > head->val)) {
                max += index;
                if (index < min) min = index;
                index = 0;
              }
              prevPrevVal = prevVal;
              prevVal = head->val;
              head = head->next;
              ++index;
            }

            return {min, max};
          }
          prevPrevVal = prevVal;
          prevVal = head->val;
          head = head->next;
          ++index;
        }
        return {-1, -1};
      }
      prevPrevVal = prevVal;
      prevVal = head->val;
      head = head->next;
    }
    return {-1, -1};
  }
};
