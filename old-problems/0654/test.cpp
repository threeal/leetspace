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

TEST_CASE("654. Maximum Binary Tree") {
  SECTION("Example 1") {
    std::vector<int> nums{3, 2, 1, 6, 0, 5};
    TreeNode* root{Solution{}.constructMaximumBinaryTree(nums)};

    std::vector<std::optional<int>> expected{
        6, 3, 5, null, 2, 0, null, null, 1};

    REQUIRE(from_tree(root) == expected);
  }

  SECTION("Example 2") {
    std::vector<int> nums{3, 2, 1};
    TreeNode* root{Solution{}.constructMaximumBinaryTree(nums)};

    std::vector<std::optional<int>> expected{3, null, 2, null, 1};
    REQUIRE(from_tree(root) == expected);
  }
}
