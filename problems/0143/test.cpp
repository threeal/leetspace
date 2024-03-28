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

TEST_CASE("143. Reorder List") {
  SECTION("Example 1") {
    auto list = to_list({1, 2, 3, 4});
    Solution{}.reorderList(list);
    REQUIRE(std::vector<int>{1, 4, 2, 3} == from_list(list));
  }

  SECTION("Example 2") {
    auto list = to_list({1, 2, 3, 4, 5});
    Solution{}.reorderList(list);
    REQUIRE(std::vector<int>{1, 5, 2, 4, 3} == from_list(list));
  }
}
