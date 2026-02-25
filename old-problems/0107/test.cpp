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

const std::nullopt_t null{std::nullopt};

TreeNode* toTreeNode(const std::vector<std::optional<int>>& list) {
  if (list.empty()) return nullptr;

  TreeNode* root{new TreeNode(*list[0])};

  std::queue<TreeNode**> children{};
  children.push(&(root->left));
  children.push(&(root->right));

  for (std::size_t i{1}; i < list.size(); ++i) {
    if (list[i]) {
      TreeNode* node{new TreeNode(*list[i])};
      *children.front() = node;
      children.push(&(node->left));
      children.push(&(node->right));
    }
    children.pop();
  }

  return root;
}

TEST_CASE("107. Binary Tree Level Order Traversal II") {
  SECTION("Example 1") {
    TreeNode* root{toTreeNode({3, 9, 20, null, null, 15, 7})};
    std::vector<std::vector<int>> expected{{15, 7}, {9, 20}, {3}};
    REQUIRE(Solution{}.levelOrderBottom(root) == expected);
  }

  SECTION("Example 2") {
    TreeNode* root{toTreeNode({1})};
    std::vector<std::vector<int>> expected{{1}};
    REQUIRE(Solution{}.levelOrderBottom(root) == expected);
  }

  SECTION("Example 3") {
    TreeNode* root{toTreeNode({})};
    std::vector<std::vector<int>> expected{};
    REQUIRE(Solution{}.levelOrderBottom(root) == expected);
  }
}
