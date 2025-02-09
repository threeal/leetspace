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

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  ListNode* head{new ListNode(nums[0])};
  ListNode* node{head};
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

TEST_CASE("92. Reverse Linked List II") {
  SECTION("Example 1") {
    const auto out = Solution{}.reverseBetween(to_list({1, 2, 3, 4, 5}), 2, 4);
    REQUIRE(std::vector<int>{1, 4, 3, 2, 5} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out = Solution{}.reverseBetween(to_list({5}), 1, 1);
    REQUIRE(std::vector<int>{5} == from_list(out));
  }

  SECTION("Test Case 18") {
    const auto out = Solution{}.reverseBetween(to_list({3, 5}), 1, 2);
    REQUIRE(std::vector<int>{5, 3} == from_list(out));
  }
}
