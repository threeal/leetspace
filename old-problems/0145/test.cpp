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

TEST_CASE("145. Binary Tree Postorder Traversal") {
  SECTION("Example 1") {
    auto output = Solution{}.postorderTraversal(to_tree({1, std::nullopt, 2, 3}));
    REQUIRE(output == std::vector<int>{3, 2, 1});
  }

  SECTION("Example 2") {
    auto output = Solution{}.postorderTraversal(to_tree({}));
    REQUIRE(output == std::vector<int>{});
  }

  SECTION("Example 3") {
    auto output = Solution{}.postorderTraversal(to_tree({1}));
    REQUIRE(output == std::vector<int>{1});
  }
}
