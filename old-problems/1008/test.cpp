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

TEST_CASE("1008. Construct Binary Search Tree from Preorder Traversal") {
  SECTION("Example 1") {
    std::vector<int> preorder{8, 5, 1, 7, 10, 12};
    TreeNode* root{Solution{}.bstFromPreorder(preorder)};

    std::vector<std::optional<int>> expected{8, 5, 10, 1, 7, null, 12};
    REQUIRE(from_tree(root) == expected);
  }

  SECTION("Example 2") {
    std::vector<int> preorder{1, 3};
    TreeNode* root{Solution{}.bstFromPreorder(preorder)};

    std::vector<std::optional<int>> expected{1, null, 3};
    REQUIRE(from_tree(root) == expected);
  }
}
