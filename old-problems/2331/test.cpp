struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
  TreeNode(int val, TreeNode* left, TreeNode* right) : val{val}, left{left}, right{right} {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

TreeNode* from_list(const std::vector<std::optional<int>>& list) {
  if (list.empty()) return nullptr;

  auto root{new TreeNode(*list[0])};

  std::queue<TreeNode**> children{};
  children.push(&(root->left));
  children.push(&(root->right));

  for (std::size_t i{1}; i < list.size(); ++i) {
    if (list[i]) {
      auto node{new TreeNode(*list[i])};
      *children.front() = node;
      children.push(&(node->left));
      children.push(&(node->right));
    }
    children.pop();
  }

  return root;
}

TEST_CASE("2331. Evaluate Boolean Binary Tree") {
  SECTION("Example 1") {
    REQUIRE(Solution{}.evaluateTree(from_list({2, 1, 3, std::nullopt, std::nullopt, 0, 1})));
  }

  SECTION("Example 2") {
    REQUIRE_FALSE(Solution{}.evaluateTree(from_list({0})));
  }
}
