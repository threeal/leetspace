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

TEST_CASE("101. Symmetric Tree") {
  SECTION("Example 1") {
    auto root = to_tree({1, 2, 2, 3, 4, 4, 3});
    REQUIRE(Solution{}.isSymmetric(root));
  }

  SECTION("Example 1") {
    auto root = to_tree({1, 2, 2, std::nullopt, 3, std::nullopt, 3});
    REQUIRE_FALSE(Solution{}.isSymmetric(root));
  }

  SECTION("Test Case 168") {
    auto root = to_tree({1, 2, 3});
    REQUIRE_FALSE(Solution{}.isSymmetric(root));
  }
}
