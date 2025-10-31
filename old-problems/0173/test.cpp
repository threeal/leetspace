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

const auto null = std::nullopt;

TreeNode* toTree(const std::vector<std::optional<int>>& list) {
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

TEST_CASE("173. Binary Search Tree Iterator") {
  SECTION("Example 1") {
    BSTIterator it(toTree({7, 3, 15, null, null, 9, 20}));
    REQUIRE(it.next() == 3);
    REQUIRE(it.next() == 7);
    REQUIRE(it.hasNext());
    REQUIRE(it.next() == 9);
    REQUIRE(it.hasNext());
    REQUIRE(it.next() == 15);
    REQUIRE(it.hasNext());
    REQUIRE(it.next() == 20);
    REQUIRE_FALSE(it.hasNext());
  }
}
