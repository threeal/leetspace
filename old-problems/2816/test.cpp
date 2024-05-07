#include <catch2/catch_test_macros.hpp>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#include "solution.cpp"

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head = new ListNode(nums[0]);
  auto end = head;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    end->next = new ListNode(nums[i]);
    end = end->next;
  }
  return head;
}

std::vector<int> from_list(ListNode* head) {
  std::vector<int> nums{};
  while (head != nullptr) {
    nums.push_back(head->val);
    head = head->next;
  }
  return nums;
}

TEST_CASE("2816. Double a Number Represented as a Linked List") {
  SECTION("Example 1") {
    const auto out = Solution{}.doubleIt(to_list({1, 8, 9}));
    REQUIRE(std::vector<int>{3, 7, 8} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out = Solution{}.doubleIt(to_list({9, 9, 9}));
    REQUIRE(std::vector<int>{1, 9, 9, 8} == from_list(out));
  }
}
