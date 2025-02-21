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

std::vector<std::optional<int>> from_tree(TreeNode* root) {
  if (root == nullptr) return {};
  std::vector<std::optional<int>> list{};

  std::queue<TreeNode*> nodes{};
  nodes.push(root);

  while (!nodes.empty()) {
    if (nodes.front() == nullptr) {
      list.push_back(null);
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

TEST_CASE("114. Flatten Binary Tree to Linked List") {
  SECTION("Example 1") {
    auto root = to_tree({1, 2, 5, 3, 4, null, 6});
    Solution{}.flatten(root);
    auto actual = from_tree(root);
    std::vector<std::optional<int>> expected{
        1, null, 2, null, 3, null, 4, null, 5, null, 6};
    REQUIRE(actual == expected);
  }

  SECTION("Example 2") {
    auto root = to_tree({});
    Solution{}.flatten(root);
    auto actual = from_tree(root);
    std::vector<std::optional<int>> expected{};
    REQUIRE(actual == expected);
  }

  SECTION("Example 3") {
    auto root = to_tree({0});
    Solution{}.flatten(root);
    auto actual = from_tree(root);
    std::vector<std::optional<int>> expected{0};
    REQUIRE(actual == expected);
  }
}
