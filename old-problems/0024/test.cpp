#include <catch2/catch_test_macros.hpp>

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode* next) : val{x}, next{next} {}
};

#include "solution.cpp"

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

TEST_CASE("24. Swap Nodes in Pairs") {
  SECTION("Example 1") {
    const auto out{Solution{}.swapPairs(to_list({1, 2, 3, 4}))};
    REQUIRE(std::vector<int>{2, 1, 4, 3} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out{Solution{}.swapPairs(to_list({}))};
    REQUIRE(std::vector<int>{} == from_list(out));
  }

  SECTION("Example 3") {
    const auto out{Solution{}.swapPairs(to_list({1}))};
    REQUIRE(std::vector<int>{1} == from_list(out));
  }
}
