struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
  TreeNode(int val, TreeNode* left, TreeNode* right)
      : val{val}, left{left}, right{right} {}

  ~TreeNode() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

TreeNode* to_tree(const std::vector<std::optional<int>>& list) {
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

std::vector<std::optional<int>> from_tree(TreeNode* root) {
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

TEST_CASE("2415. Reverse Odd Levels of Binary Tree") {
  SECTION("Example 1") {
    const auto root = to_tree({2, 3, 5, 8, 13, 21, 34});
    const auto actual = from_tree(Solution{}.reverseOddLevels(root));
    const std::vector<std::optional<int>> expected{2, 5, 3, 8, 13, 21, 34};
    REQUIRE(actual == expected);
    delete root;
  }

  SECTION("Example 2") {
    const auto root = to_tree({7, 13, 11});
    const auto actual = from_tree(Solution{}.reverseOddLevels(root));
    const std::vector<std::optional<int>> expected{7, 11, 13};
    REQUIRE(actual == expected);
    delete root;
  }

  SECTION("Example 3") {
    const auto root = to_tree({0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2});
    const auto actual = from_tree(Solution{}.reverseOddLevels(root));
    const std::vector<std::optional<int>> expected{0, 2, 1, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1};
    REQUIRE(actual == expected);
    delete root;
  }
}
