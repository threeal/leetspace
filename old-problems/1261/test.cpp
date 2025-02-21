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

TEST_CASE("1261. Find Elements in a Contaminated Binary Tree") {
  SECTION("Example 1") {
    FindElements findElements(to_tree({-1, null, -1}));
    REQUIRE_FALSE(findElements.find(1));
    REQUIRE(findElements.find(2));
  }

  SECTION("Example 2") {
    FindElements findElements(to_tree({-1, -1, -1, -1, -1}));
    REQUIRE(findElements.find(1));
    REQUIRE(findElements.find(3));
    REQUIRE_FALSE(findElements.find(5));
  }

  SECTION("Example 3") {
    FindElements findElements(to_tree({-1, null, -1, -1, null, -1}));
    REQUIRE(findElements.find(2));
    REQUIRE_FALSE(findElements.find(3));
    REQUIRE_FALSE(findElements.find(4));
    REQUIRE(findElements.find(5));
  }
}
