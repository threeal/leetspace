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

#include <algorithm>
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

std::vector<std::vector<int>> from_lists(const std::vector<ListNode*>& heads) {
  std::vector<std::vector<int>> nums(heads.size());
  for (std::size_t i{0}; i < heads.size(); ++i) {
    auto head = heads[i];
    while (head != nullptr) {
      nums[i].push_back(head->val);
      head = head->next;
    }
  }
  return nums;
}

TEST_CASE("725. Split Linked List in Parts") {
  SECTION("Example 1") {
    const auto output = Solution{}.splitListToParts(to_list({1, 2, 3}), 5);
    const std::vector<std::vector<int>> expected{{1}, {2}, {3}, {}, {}};
    REQUIRE(from_lists(output) == expected);
  }

  SECTION("Example 2") {
    const auto output = Solution{}.splitListToParts(
        to_list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), 3);
    const std::vector<std::vector<int>> expected{
        {1, 2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    REQUIRE(from_lists(output) == expected);
  }
}
