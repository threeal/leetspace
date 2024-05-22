#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<
        std::tuple<int, ListNode*>,
        std::vector<std::tuple<int, ListNode*>>,
        std::greater<std::tuple<int, ListNode*>>>
        queue{};

    for (const auto list : lists) {
      if (list == nullptr) continue;
      queue.push({list->val, list});
    }

    if (queue.empty()) return nullptr;

    auto head{std::get<1>(queue.top())};
    queue.pop();

    if (head->next != nullptr)
      queue.push({head->next->val, head->next});

    auto node{head};
    while (!queue.empty()) {
      node->next = std::get<1>(queue.top());
      queue.pop();

      if (node->next->next != nullptr)
        queue.push({node->next->next->val, node->next->next});

      node = node->next;
    }

    return head;
  }
};
