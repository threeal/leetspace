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

std::vector<std::optional<int>> to_list(TreeNode* root) {
  if (root == nullptr) return {};

  std::vector<std::optional<int>> list{};

  std::queue<TreeNode*> nodes{};
  nodes.push(root);

  while (!nodes.empty()) {
    if (nodes.front() == nullptr) {
      list.push_back(std::nullopt);
    } else {
      list.push_back(nodes.front()->val);
      nodes.push(nodes.front()->left);
      nodes.push(nodes.front()->right);
    }
    nodes.pop();
  }

  while (!list.back()) {
    list.pop_back();
  }

  return list;
}

TEST_CASE("2196. Create Binary Tree From Descriptions") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> descriptions{
        {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    auto res = Solution{}.createBinaryTree(descriptions);
    std::vector<std::optional<int>> expected{
        50, 20, 80, 15, 17, 19};
    REQUIRE(to_list(res) == expected);
  }

  SECTION("Example 1") {
    std::vector<std::vector<int>> descriptions{{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
    auto res = Solution{}.createBinaryTree(descriptions);
    std::vector<std::optional<int>> expected{
        1, 2, std::nullopt, std::nullopt, 3, 4};
    REQUIRE(to_list(res) == expected);
  }
}
