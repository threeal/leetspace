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
  auto head = new ListNode(nums[0]);
  auto node = head;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    node->next = new ListNode(nums[i]);
    node = node->next;
  }
  return head;
}

TEST_CASE("2326. Spiral Matrix IV") {
  SECTION("Example 1") {
    const auto actual = Solution{}.spiralMatrix(
        3, 5, to_list({3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0}));
    std::vector<std::vector<int>> expected{
        {3, 0, 2, 6, 8},
        {5, 0, -1, -1, 1},
        {5, 2, 4, 9, 7}};
    REQUIRE(expected == actual);
  }

  SECTION("Example 2") {
    const auto actual = Solution{}.spiralMatrix(1, 4, to_list({0, 1, 2}));
    std::vector<std::vector<int>> expected{{0, 1, 2, -1}};
    REQUIRE(expected == actual);
  }

  SECTION("Test Case 46") {
    const auto actual = Solution{}.spiralMatrix(
        10, 1, to_list({8, 24, 5, 21, 10, 11, 11, 12, 6, 17}));
    std::vector<std::vector<int>> expected{
        {8}, {24}, {5}, {21}, {10}, {11}, {11}, {12}, {6}, {17}};
    REQUIRE(expected == actual);
  }
}
