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

TEST_CASE("2058. Find the Minimum and Maximum Number of Nodes Between Critical Points") {
  SECTION("Example 1") {
    const auto out = Solution{}.nodesBetweenCriticalPoints(to_list({3, 1}));
    REQUIRE(std::vector<int>{-1, -1} == out);
  }

  SECTION("Example 2") {
    const auto out = Solution{}.nodesBetweenCriticalPoints(
        to_list({5, 3, 1, 2, 5, 1, 2}));
    REQUIRE(std::vector<int>{1, 3} == out);
  }

  SECTION("Example 3") {
    const auto out = Solution{}.nodesBetweenCriticalPoints(
        to_list({1, 3, 2, 2, 3, 2, 2, 2, 7}));
    REQUIRE(std::vector<int>{3, 3} == out);
  }

  SECTION("Test Case 50") {
    const auto out = Solution{}.nodesBetweenCriticalPoints(
        to_list({6, 8, 4, 1, 9, 6, 6, 10, 6}));
    REQUIRE(std::vector<int>{1, 6} == out);
  }
}
