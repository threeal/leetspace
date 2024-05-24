#include <catch2/catch_test_macros.hpp>

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

#include <vector>

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head{new ListNode(nums[0])};
  auto node{head};
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

TEST_CASE("25. Reverse Nodes in k-Group") {
  SECTION("Example 1") {
    const auto output{Solution{}.reverseKGroup(to_list({1, 2, 3, 4, 5}), 2)};
    REQUIRE(std::vector<int>{2, 1, 4, 3, 5} == from_list(output));
  }

  SECTION("Example 2") {
    const auto output{Solution{}.reverseKGroup(to_list({1, 2, 3, 4, 5}), 3)};
    REQUIRE(std::vector<int>{3, 2, 1, 4, 5} == from_list(output));
  }
}
