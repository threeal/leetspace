#include <queue>
#include <vector>

class Solution {
 public:
  struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
      return a->val > b->val;
    }
  };

  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> queue{};

    for (const auto list : lists) {
      if (list == nullptr) continue;
      queue.push(list);
    }

    if (queue.empty()) return nullptr;

    auto head{queue.top()};
    queue.pop();

    if (head->next != nullptr) queue.push(head->next);

    auto node{head};
    while (!queue.empty()) {
      node->next = queue.top();
      queue.pop();

      if (node->next->next != nullptr) queue.push(node->next->next);

      node = node->next;
    }

    return head;
  }
};
