#include <unordered_set>
#include <vector>

class Solution {
 public:
  ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
    std::unordered_set<int> exists(nums.begin(), nums.end());

    ListNode** node = &head;
    while (*node != nullptr) {
      if (exists.contains((*node)->val)) {
        *node = (*node)->next;
      } else {
        node = &((*node)->next);
      }
    }

    return head;
  }
};
