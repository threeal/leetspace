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

TEST_CASE("1290. Convert Binary Number in a Linked List to Integer") {
  SECTION("Example 1") {
    const int num{Solution{}.getDecimalValue(to_list({1, 0, 1}))};
    REQUIRE(num == 5);
  }

  SECTION("Example 2") {
    const int num{Solution{}.getDecimalValue(to_list({0}))};
    REQUIRE(num == 0);
  }
}
