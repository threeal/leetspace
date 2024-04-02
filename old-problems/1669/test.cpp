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

TEST_CASE("1669. Merge In Between Linked Lists") {
  SECTION("Example 1") {
    const auto out = Solution{}.mergeInBetween(to_list({10, 1, 13, 6, 9, 5}), 3, 4, to_list({1000000, 1000001, 1000002}));
    REQUIRE(std::vector<int>{10, 1, 13, 1000000, 1000001, 1000002, 5} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out = Solution{}.mergeInBetween(to_list({0, 1, 2, 3, 4, 5, 6}), 2, 5, to_list({1000000, 1000001, 1000002, 1000003, 1000004}));
    REQUIRE(std::vector<int>{0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6} == from_list(out));
  }
}
