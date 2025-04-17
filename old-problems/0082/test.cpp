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

TEST_CASE("82. Remove Duplicates from Sorted List II") {
  SECTION("Example 1") {
    const ListNode* out{
        Solution{}.deleteDuplicates(to_list({1, 2, 3, 3, 4, 4, 5}))};
    REQUIRE(std::vector<int>{1, 2, 5} == from_list(out));
  }

  SECTION("Example 2") {
    const ListNode* out{Solution{}.deleteDuplicates(to_list({1, 1, 1, 2, 3}))};
    REQUIRE(std::vector<int>{2, 3} == from_list(out));
  }
}
