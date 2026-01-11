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

TEST_CASE("1721. Swapping Nodes in a Linked List") {
  SECTION("Example 1") {
    ListNode* head{tolistNode({1, 2, 3, 4, 5})};
    ListNode* actual{Solution{}.swapNodes(head, 2)};
    std::vector<int> expected{1, 4, 3, 2, 5};
    REQUIRE(fromListNode(actual) == expected);
  }

  SECTION("Example 2") {
    ListNode* head{tolistNode({7, 9, 6, 6, 7, 8, 3, 0, 9, 5})};
    ListNode* actual{Solution{}.swapNodes(head, 5)};
    std::vector<int> expected{7, 9, 6, 6, 8, 7, 3, 0, 9, 5};
    REQUIRE(fromListNode(actual) == expected);
  }
}
