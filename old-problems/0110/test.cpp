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

TEST_CASE("110. Balanced Binary Tree") {
  SECTION("Example 1") {
    TreeNode* root{toTreeNode({3, 9, 20, null, null, 15, 7})};
    REQUIRE(Solution{}.isBalanced(root));
  }

  SECTION("Example 2") {
    TreeNode* root{toTreeNode({1, 2, 2, 3, 3, null, null, 4, 4})};
    REQUIRE_FALSE(Solution{}.isBalanced(root));
  }

  SECTION("Example 3") {
    TreeNode* root{toTreeNode({})};
    REQUIRE(Solution{}.isBalanced(root));
  }
}
