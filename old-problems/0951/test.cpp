struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
  TreeNode(int val, TreeNode* left, TreeNode* right)
      : val{val}, left{left}, right{right} {}

  ~TreeNode() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }
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

TEST_CASE("951. Flip Equivalent Binary Trees") {
  SECTION("Example 1") {
    const auto root1 = to_tree(
        {1, 2, 3, 4, 5, 6, std::nullopt, std::nullopt, std::nullopt, 7, 8});

    const auto root2 = to_tree(
        {1, 3, 2, std::nullopt, 6, 4, 5, std::nullopt, std::nullopt,
         std::nullopt, std::nullopt, 8, 7});

    REQUIRE(Solution{}.flipEquiv(root1, root2));

    delete root1;
    delete root2;
  }

  SECTION("Example 2") {
    REQUIRE(Solution{}.flipEquiv(nullptr, nullptr));
  }

  SECTION("Example 3") {
    const auto root2 = to_tree({1});
    REQUIRE_FALSE(Solution{}.flipEquiv(nullptr, root2));
    delete root2;
  }
}
