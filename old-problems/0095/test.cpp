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

std::vector<std::optional<int>> from_tree(TreeNode* root) {
  if (root == nullptr) return {};
  std::vector<std::optional<int>> list{};

  std::queue<TreeNode*> nodes{};
  nodes.push(root);

  while (!nodes.empty()) {
    if (nodes.front() == nullptr) {
      list.push_back(null);
    } else {
      list.push_back(nodes.front()->val);
      nodes.push(nodes.front()->left);
      nodes.push(nodes.front()->right);
    }
    nodes.pop();
  }

  while (!list.back()) list.pop_back();
  return list;
}

TEST_CASE("95. Unique Binary Search Trees II") {
  SECTION("Example 1") {
    auto trees = Solution{}.generateTrees(3);
    std::vector<std::vector<std::optional<int>>> actual(trees.size());
    for (std::size_t i{0}; i < trees.size(); ++i) {
      actual[i] = from_tree(trees[i]);
    }
    std::vector<std::vector<std::optional<int>>> expected{
      {1,null,2,null,3},
      {1,null,3,2},
      {2,1,3},
      {3,1,null,null,2},
      {3,2,null,1}
    };
    REQUIRE(actual == expected);
  }

  SECTION("Example 1") {
    auto trees = Solution{}.generateTrees(3);
    std::vector<std::vector<std::optional<int>>> actual(trees.size());
    for (std::size_t i{0}; i < trees.size(); ++i) {
      actual[i] = from_tree(trees[i]);
    }
    std::vector<std::vector<std::optional<int>>> expected{{1}};
    REQUIRE(actual == expected);
  }
}
