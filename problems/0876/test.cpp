#include <catch2/catch_test_macros.hpp>
#include <ostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#include "solution.cpp"

bool operator==(const ListNode& lhs, const ListNode& rhs) {
  return lhs.val == rhs.val;
}

std::ostream& operator<<(std::ostream& os, ListNode node) {
  return os << node.val;
}

TEST_CASE("876. Middle of the Linked List") {
  SECTION("Example 1") {
    ListNode middle(3, new ListNode(4, new ListNode(5)));
    ListNode head(1, new ListNode(2, &middle));
    REQUIRE(*Solution{}.middleNode(&head) == middle);
  }

  SECTION("Example 2") {
    ListNode middle(4, new ListNode(5, new ListNode(6)));
    ListNode head(1, new ListNode(2, new ListNode(3, &middle)));
    REQUIRE(*Solution{}.middleNode(&head) == middle);
  }
}
