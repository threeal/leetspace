struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val{x}, left{left}, right{right} {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

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

TEST_CASE("1530. Number of Good Leaf Nodes Pairs") {
  SECTION("Example 1") {
    const auto output = Solution{}.countPairs(
        from_list({1, 2, 3, std::nullopt, 4}), 3);
    REQUIRE(output == 1);
  }

  SECTION("Example 2") {
    const auto output = Solution{}.countPairs(
        from_list({1, 2, 3, 4, 5, 6, 7}), 3);
    REQUIRE(output == 2);
  }

  SECTION("Example 2") {
    const auto output = Solution{}.countPairs(
        from_list({7, 1, 4, 6, std::nullopt, 5, 3, std::nullopt, std::nullopt,
                   std::nullopt, std::nullopt, std::nullopt, 2}),
        3);
    REQUIRE(output == 1);
  }
}
