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

TEST_CASE("113. Path Sum II") {
  SECTION("Example 1") {
    auto root = to_tree({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1});
    auto actual = Solution{}.pathSum(root, 22);
    auto expected = std::vector<std::vector<int>>{{5, 4, 11, 2}, {5, 8, 4, 5}};
    REQUIRE(actual == expected);
  }

  SECTION("Example 2") {
    auto root = to_tree({1, 2, 3});
    auto actual = Solution{}.pathSum(root, 5);
    REQUIRE(actual == std::vector<std::vector<int>>{});
  }

  SECTION("Example 3") {
    auto root = to_tree({1, 2});
    auto actual = Solution{}.pathSum(root, 0);
    REQUIRE(actual == std::vector<std::vector<int>>{});
  }
}
