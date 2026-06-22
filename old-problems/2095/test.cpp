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

ListNode* tolistNode(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  ListNode* head{new ListNode(nums[0])};
  ListNode* node{head};
  for (std::size_t i = 1; i < nums.size(); ++i) {
    node->next = new ListNode(nums[i]);
    node = node->next;
  }
  return head;
}

std::vector<int> fromListNode(const ListNode* node) {
  std::vector<int> nums{};
  while (node != nullptr) {
    nums.push_back(node->val);
    node = node->next;
  }
  return nums;
}

TEST_CASE("2095. Delete the Middle Node of a Linked List") {
  SECTION("Example 1") {
    ListNode* head{tolistNode({1, 3, 4, 7, 1, 2, 6})};
    ListNode* actual{Solution{}.deleteMiddle(head)};
    std::vector<int> expected{1, 3, 4, 1, 2, 6};
    REQUIRE(fromListNode(actual) == expected);
  }

  SECTION("Example 2") {
    ListNode* head{tolistNode({1, 2, 3, 4})};
    ListNode* actual{Solution{}.deleteMiddle(head)};
    std::vector<int> expected{1, 2, 4};
    REQUIRE(fromListNode(actual) == expected);
  }

  SECTION("Example 3") {
    ListNode* head{tolistNode({2, 1})};
    ListNode* actual{Solution{}.deleteMiddle(head)};
    std::vector<int> expected{2};
    REQUIRE(fromListNode(actual) == expected);
  }
}
