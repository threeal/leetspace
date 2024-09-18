struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode* next) : val{x}, next{next} {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  const auto head = new ListNode(nums[0]);
  auto node = head;
  for (std::size_t i{1}; i < nums.size(); ++i) {
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

TEST_CASE("2807. Insert Greatest Common Divisors in Linked List") {
  SECTION("Example 1") {
    const auto head = to_list({18, 6, 10, 3});
    const auto out = Solution{}.insertGreatestCommonDivisors(head);
    REQUIRE(std::vector<int>{18, 6, 6, 2, 10, 1, 3} == from_list(out));
  }

  SECTION("Example 2") {
    const auto head = to_list({7});
    const auto out = Solution{}.insertGreatestCommonDivisors(head);
    REQUIRE(std::vector<int>{7} == from_list(out));
  }
}
