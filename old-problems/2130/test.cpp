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

TEST_CASE("2130. Maximum Twin Sum of a Linked List") {
  SECTION("Example 1") {
    const int sum{Solution{}.pairSum(to_list({5, 4, 2, 1}))};
    REQUIRE(sum == 6);
  }

  SECTION("Example 2") {
    const int sum{Solution{}.pairSum(to_list({4, 2, 2, 3}))};
    REQUIRE(sum == 7);
  }

  SECTION("Example 3") {
    const int sum{Solution{}.pairSum(to_list({1, 100000}))};
    REQUIRE(sum == 100001);
  }
}
