struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode* next) : val{x}, next{next} {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

ListNode* to_list(const std::vector<int>& list) {
  if (list.empty()) return nullptr;
  const auto head = new ListNode(list[0]);
  auto node = head;
  for (std::size_t i{1}; i < list.size(); ++i) {
    node->next = new ListNode(list[i]);
    node = node->next;
  }
  return head;
}

TreeNode* to_tree(const std::vector<std::optional<int>>& list) {
  if (list.empty()) return nullptr;
  auto root = new TreeNode(*list[0]);
  std::queue<TreeNode**> children{};
  children.push(&(root->left));
  children.push(&(root->right));
  for (std::size_t i{1}; i < list.size(); ++i) {
    if (list[i]) {
      auto node = new TreeNode(*list[i]);
      *children.front() = node;
      children.push(&(node->left));
      children.push(&(node->right));
    }
    children.pop();
  }
  return root;
}

TEST_CASE("1367. Linked List in Binary Tree") {
  SECTION("Example 1") {
    auto head = to_list({4, 2, 8});
    auto root = to_tree(
        {1, 4, 4, std::nullopt, 2, 2, std::nullopt, 1, std::nullopt, 6, 8,
         std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1, 3});
    REQUIRE(Solution{}.isSubPath(head, root));
  }

  SECTION("Example 2") {
    auto head = to_list({1, 4, 2, 6});
    auto root = to_tree(
        {1, 4, 4, std::nullopt, 2, 2, std::nullopt, 1, std::nullopt, 6, 8,
         std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1, 3});
    REQUIRE(Solution{}.isSubPath(head, root));
  }

  SECTION("Example 3") {
    auto head = to_list({1, 4, 2, 6, 8});
    auto root = to_tree(
        {1, 4, 4, std::nullopt, 2, 2, std::nullopt, 1, std::nullopt, 6, 8,
         std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1, 3});
    REQUIRE_FALSE(Solution{}.isSubPath(head, root));
  }
}
