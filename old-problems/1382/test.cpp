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

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
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

int get_depth(const TreeNode* node) {
  if (node == nullptr) return 0;
  return 1 + std::max(get_depth(node->left), get_depth(node->right));
}

TEST_CASE("1382. Balance a Binary Search Tree") {
  SECTION("Example 1") {
    const TreeNode* output{Solution{}.balanceBST(from_list({1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4, std::nullopt, std::nullopt}))};
    REQUIRE(std::abs(get_depth(output->left) - get_depth(output->right)) <= 1);
  }

  SECTION("Example 2") {
    const TreeNode* output{Solution{}.balanceBST(from_list({2, 1, 3}))};
    REQUIRE(std::abs(get_depth(output->left) - get_depth(output->right)) <= 1);
  }
}
