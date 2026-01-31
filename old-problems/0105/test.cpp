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

const std::nullopt_t null{std::nullopt};

std::vector<std::optional<int>> fromTreeNode(TreeNode* root) {
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

TEST_CASE("105. Construct Binary Tree from Preorder and Inorder Traversal") {
  SECTION("Example 1") {
    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode* actual{Solution{}.buildTree(preorder, inorder)};
    std::vector<std::optional<int>> expected{3, 9, 20, null, null, 15, 7};
    REQUIRE(fromTreeNode(actual) == expected);
  }

  SECTION("Example 2") {
    std::vector<int> preorder{-1};
    std::vector<int> inorder{-1};
    TreeNode* actual{Solution{}.buildTree(preorder, inorder)};
    std::vector<std::optional<int>> expected{-1};
    REQUIRE(fromTreeNode(actual) == expected);
  }
}
