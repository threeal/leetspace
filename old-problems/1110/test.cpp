struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val{x}, left{left}, right{right} {}
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

TEST_CASE("1110. Delete Nodes And Return Forest") {
  SECTION("Example 1") {
    std::vector<int> toDelete{3, 5};
    const auto trees = Solution{}.delNodes(
        from_list({1, 2, 3, 4, 5, 6, 7}), toDelete);

    std::vector<std::vector<std::optional<int>>> actual(trees.size());
    for (std::size_t i = 0; i < trees.size(); ++i) {
      actual[i] = to_list(trees[i]);
    }

    const std::vector<std::vector<std::optional<int>>> expected{
        {1, 2, std::nullopt, 4}, {6}, {7}};

    REQUIRE(actual == expected);
  }

  SECTION("Example 2") {
    std::vector<int> toDelete{3};
    const auto trees = Solution{}.delNodes(
        from_list({1, 2, 4, std::nullopt, 3}), toDelete);

    std::vector<std::vector<std::optional<int>>> actual(trees.size());
    for (std::size_t i = 0; i < trees.size(); ++i) {
      actual[i] = to_list(trees[i]);
    }

    const std::vector<std::vector<std::optional<int>>> expected{
        {1, 2, 4}};

    REQUIRE(actual == expected);
  }
}
