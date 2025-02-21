struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head = new ListNode(nums[0]);
  auto node = head;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    node->next = new ListNode(nums[i]);
    node = node->next;
  }
  return head;
}

std::vector<int> from_list(const ListNode* node) {
  std::vector<int> nums{};
  while (node != nullptr) {
    nums.push_back(node->val);
    node = node->next;
  }
  return nums;
}

int list_distance(const ListNode* node1, const ListNode* node2) {
  if (node1 != nullptr && node2 != nullptr) {
    int pos{0};
    for (auto node = node1; node != nullptr; node = node->next) {
      if (node == node2) return pos;
      ++pos;
    }
  }
  return -1;
}

TEST_CASE("142. Linked List Cycle II") {
  SECTION("Example 1") {
    auto head = to_list({1, 2, 0, -4});
    head->next->next->next->next = head->next;

    const auto out = Solution{}.detectCycle(head);
    REQUIRE(list_distance(head, out) == 1);
  }

  SECTION("Example 2") {
    auto head = to_list({1, 2, 0, -4});
    head->next->next = head;

    const auto out = Solution{}.detectCycle(head);
    REQUIRE(list_distance(head, out) == 0);
  }

  SECTION("Example 3") {
    auto head = to_list({1});
    const auto out = Solution{}.detectCycle(head);
    REQUIRE(list_distance(head, out) == -1);
  }
}
