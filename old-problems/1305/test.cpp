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

TEST_CASE("1305. All Elements in Two Binary Search Trees") {
  SECTION("Example 1") {
    TreeNode* root1{to_tree({2, 1, 4})};
    TreeNode* root2{to_tree({1, 0, 3})};
    std::vector<int> nums{Solution{}.getAllElements(root1, root2)};
    REQUIRE(nums == std::vector<int>{0, 1, 1, 2, 3, 4});
  }

  SECTION("Example 2") {
    TreeNode* root1{to_tree({1, null, 8})};
    TreeNode* root2{to_tree({8, 1})};
    std::vector<int> nums{Solution{}.getAllElements(root1, root2)};
    REQUIRE(nums == std::vector<int>{1, 1, 8, 8});
  }
}
