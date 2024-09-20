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
#include <vector>

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

TEST_CASE("2. Add Two Numbers") {
  SECTION("Example 1") {
    const auto out = Solution{}.addTwoNumbers(
        to_list({2, 4, 3}), to_list({5, 6, 4}));
    REQUIRE(std::vector<int>{7, 0, 8} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out = Solution{}.addTwoNumbers(to_list({0}), to_list({0}));
    REQUIRE(std::vector<int>{0} == from_list(out));
  }

  SECTION("Example 3") {
    const auto out = Solution{}.addTwoNumbers(
        to_list({9, 9, 9, 9, 9, 9, 9}), to_list({9, 9, 9, 9}));
    REQUIRE(std::vector<int>{8, 9, 9, 9, 0, 0, 0, 1} == from_list(out));
  }
}
