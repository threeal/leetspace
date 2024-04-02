#include <catch2/catch_test_macros.hpp>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head = new ListNode(nums[0]);
  auto node = head;
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

#include "solution.cpp"

TEST_CASE("234. Palindrome Linked List") {
  SECTION("Example 1") {
    REQUIRE(Solution{}.isPalindrome(to_list({1, 2, 2, 1})));
  }

  SECTION("Example 2") {
    REQUIRE_FALSE(Solution{}.isPalindrome(to_list({1, 2})));
  }
}
