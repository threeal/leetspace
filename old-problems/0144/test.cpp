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

const auto null = std::nullopt;

TEST_CASE("144. Binary Tree Preorder Traversal") {
  SECTION("Example 1") {
    auto output = Solution{}.preorderTraversal(to_tree({1, null, 2, 3}));
    REQUIRE(std::vector<int>{1, 2, 3} == output);
  }

  SECTION("Example 2") {
    auto output = Solution{}.preorderTraversal(
        to_tree({1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9}));
    REQUIRE(std::vector<int>{1, 2, 4, 5, 6, 7, 3, 8, 9} == output);
  }

  SECTION("Example 3") {
    auto output = Solution{}.preorderTraversal(nullptr);
    REQUIRE(std::vector<int>{} == output);
  }

  SECTION("Example 4") {
    auto output = Solution{}.preorderTraversal(to_tree({1}));
    REQUIRE(std::vector<int>{1} == output);
  }
}
