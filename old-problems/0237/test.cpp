#include <catch2/catch_test_macros.hpp>

struct ListNode {
  int val;
  ListNode* next;
};

#include "solution.cpp"

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head = new ListNode{.val = nums[0], .next = nullptr};
  auto node = head;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    node->next = new ListNode{.val = nums[i], .next = nullptr};
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

TEST_CASE("237. Delete Node in a Linked List") {
  SECTION("Example 1") {
    auto head = to_list({4, 5, 1, 9});
    Solution{}.deleteNode(head->next);
    REQUIRE(from_list(head) == std::vector<int>{4, 1, 9});
  }

  SECTION("Example 2") {
    auto head = to_list({4, 5, 1, 9});
    Solution{}.deleteNode(head->next->next);
    REQUIRE(from_list(head) == std::vector<int>{4, 5, 9});
  }
}
