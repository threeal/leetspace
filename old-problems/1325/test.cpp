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

std::vector<std::optional<int>> to_list(TreeNode* root) {
  if (root == nullptr) return {};

  std::vector<std::optional<int>> list{};

  std::queue<TreeNode*> nodes{};
  nodes.push(root);
  while (!nodes.empty()) {
    if (nodes.front() == nullptr) {
      list.push_back(std::nullopt);
    } else {
      list.push_back(nodes.front()->val);
      nodes.push(nodes.front()->left);
      nodes.push(nodes.front()->right);
    }
    nodes.pop();
  }

  while (!list.back()) list.pop_back();
  return list;
}

TEST_CASE("1325. Delete Leaves With a Given Value") {
  SECTION("Example 1") {
    TreeNode* output{Solution{}.removeLeafNodes(from_list({1, 2, 3, 2, std::nullopt, 2, 4}), 2)};
    REQUIRE(to_list(output) == std::vector<std::optional<int>>{1, std::nullopt, 3, std::nullopt, 4});
  }

  SECTION("Example 2") {
    TreeNode* output{Solution{}.removeLeafNodes(from_list({1, 3, 3, 3, 2}), 3)};
    REQUIRE(to_list(output) == std::vector<std::optional<int>>{1, 3, std::nullopt, std::nullopt, 2});
  }

  SECTION("Example 3") {
    TreeNode* output{Solution{}.removeLeafNodes(from_list({1, 2, std::nullopt, 2, std::nullopt, 2}), 2)};
    REQUIRE(to_list(output) == std::vector<std::optional<int>>{1});
  }
}
