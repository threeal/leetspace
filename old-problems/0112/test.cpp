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

TEST_CASE("112. Path Sum") {
  SECTION("Example 1") {
    auto root = to_tree({5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt, std::nullopt, std::nullopt, 1});
    auto output = Solution{}.hasPathSum(root, 22);
    REQUIRE(output);
  }

  SECTION("Example 2") {
    auto root = to_tree({1, 2, 3});
    auto output = Solution{}.hasPathSum(root, 5);
    REQUIRE_FALSE(output);
  }

  SECTION("Example 3") {
    auto output = Solution{}.hasPathSum(nullptr, 0);
    REQUIRE_FALSE(output);
  }

  SECTION("Test Case 72") {
    auto root = to_tree({1, 2});
    auto output = Solution{}.hasPathSum(root, 1);
    REQUIRE_FALSE(output);
  }

  SECTION("Test Case 86") {
    auto root = to_tree({-2, std::nullopt, -3});
    auto output = Solution{}.hasPathSum(root, -5);
    REQUIRE(output);
  }
}
