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
  const auto head{new ListNode(nums[0])};
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

TEST_CASE("148. Sort List") {
  SECTION("Example 1") {
    ListNode* out{Solution{}.sortList(to_list({4, 2, 1, 3}))};
    REQUIRE(std::vector<int>{1, 2, 3, 4} == from_list(out));
  }

  SECTION("Example 2") {
    ListNode* out{Solution{}.sortList(to_list({-1, 5, 3, 4, 0}))};
    REQUIRE(std::vector<int>{-1, 0, 3, 4, 5} == from_list(out));
  }

  SECTION("Example 3") {
    ListNode* out{Solution{}.sortList(nullptr)};
    REQUIRE(std::vector<int>{} == from_list(out));
  }
}
