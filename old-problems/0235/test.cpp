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

TreeNode* toTreeNode(const std::vector<std::optional<int>>& list) {
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

TreeNode* findNode(TreeNode* root, int val) {
  if (root->val == val) return root;

  if (root->left != nullptr) {
    TreeNode* left{findNode(root->left, val)};
    if (left != nullptr) return left;
  }

  if (root->right != nullptr) {
    TreeNode* right{findNode(root->right, val)};
    if (right != nullptr) return right;
  }

  return nullptr;
}

TEST_CASE("235. Lowest Common Ancestor of a Binary Search Tree") {
  SECTION("Example 1") {
    TreeNode* root{toTreeNode({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5})};
    TreeNode* p{findNode(root, 2)};
    TreeNode* q{findNode(root, 8)};
    TreeNode* output{Solution{}.lowestCommonAncestor(root, p, q)};
    REQUIRE(output->val == 6);
  }

  SECTION("Example 2") {
    TreeNode* root{toTreeNode({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5})};
    TreeNode* p{findNode(root, 2)};
    TreeNode* q{findNode(root, 4)};
    TreeNode* output{Solution{}.lowestCommonAncestor(root, p, q)};
    REQUIRE(output->val == 2);
  }

  SECTION("Example 3") {
    TreeNode* root{toTreeNode({2, 1})};
    TreeNode* p{findNode(root, 2)};
    TreeNode* q{findNode(root, 1)};
    TreeNode* output{Solution{}.lowestCommonAncestor(root, p, q)};
    REQUIRE(output->val == 2);
  }
}
