#include <catch2/catch_test_macros.hpp>

struct ListNode {
  int val;
  ListNode* next;
};

#include "solution.cpp"

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head = new ListNode({.val = nums[0], .next = nullptr});
  auto node = head;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    node->next = new ListNode({.val = nums[i], .next = nullptr});
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

TEST_CASE("2487. Remove Nodes From Linked List") {
  SECTION("Example 1") {
    const auto out = Solution{}.removeNodes(to_list({5, 2, 13, 3, 8}));
    REQUIRE(std::vector<int>{13, 8} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out = Solution{}.removeNodes(to_list({1, 1, 1, 1}));
    REQUIRE(std::vector<int>{1, 1, 1, 1} == from_list(out));
  }
}
