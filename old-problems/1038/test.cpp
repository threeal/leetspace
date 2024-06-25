struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

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

  while (!list.back()) {
    list.pop_back();
  }

  return list;
}

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

TEST_CASE("1038. Binary Search Tree to Greater Sum Tree") {
  SECTION("Example 1") {
    auto res = Solution{}.bstToGst(from_list({4, 1, 6, 0, 2, 5, 7, std::nullopt, std::nullopt, std::nullopt, 3, std::nullopt, std::nullopt, std::nullopt, 8}));
    std::vector<std::optional<int>> expected{30, 36, 21, 36, 35, 26, 15, std::nullopt, std::nullopt, std::nullopt, 33, std::nullopt, std::nullopt, std::nullopt, 8};
    REQUIRE(to_list(res) == expected);
  }

  SECTION("Example 1") {
    auto res = Solution{}.bstToGst(from_list({0, std::nullopt, 1}));
    std::vector<std::optional<int>> expected{1, std::nullopt, 1};
    REQUIRE(to_list(res) == expected);
  }
}
