#include <catch2/catch_test_macros.hpp>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#include "solution.cpp"

TEST_CASE("141. Linked List Cycle") {
  SECTION("Example 1") {
    std::vector<ListNode> nodes{
        ListNode(3),
        ListNode(2),
        ListNode(0),
        ListNode(-4),
    };
    for (std::size_t i = 1; i < nodes.size(); ++i) {
      nodes[i - 1].next = &nodes[i];
    }
    nodes[nodes.size() - 1].next = &nodes[1];
    REQUIRE(Solution{}.hasCycle(&nodes[0]));
  }

  SECTION("Example 2") {
    std::vector<ListNode> nodes{
        ListNode(1),
        ListNode(2),
    };
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[0];
    REQUIRE(Solution{}.hasCycle(&nodes[0]));
  }

  SECTION("Example 3") {
    ListNode node(1);
    REQUIRE_FALSE(Solution{}.hasCycle(&node));
  }
}
