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

TreeNode* toTreeNode(const std::vector<std::optional<int>>& list) {
  if (list.empty()) return nullptr;

  TreeNode* root{new TreeNode(*list[0])};

  std::queue<TreeNode**> children{};
  children.push(&(root->left));
  children.push(&(root->right));

  for (std::size_t i{1}; i < list.size(); ++i) {
    if (list[i]) {
      TreeNode* node{new TreeNode(*list[i])};
      *children.front() = node;
      children.push(&(node->left));
      children.push(&(node->right));
    }
    children.pop();
  }

  return root;
}

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

TEST_CASE("701. Insert into a Binary Search Tree") {
  SECTION("Example 1") {
    TreeNode* root{toTreeNode({4, 2, 7, 1, 3})};
    TreeNode* actual{Solution{}.insertIntoBST(root, 5)};
    std::vector<std::optional<int>> expected{4, 2, 7, 1, 3, 5};
    REQUIRE(fromTreeNode(actual) == expected);
  }

  SECTION("Example 2") {
    TreeNode* root{toTreeNode({40, 20, 60, 10, 30, 50, 70})};
    TreeNode* actual{Solution{}.insertIntoBST(root, 25)};
    std::vector<std::optional<int>> expected{40, 20, 60, 10, 30, 50, 70, null, null, 25};
    REQUIRE(fromTreeNode(actual) == expected);
  }

  SECTION("Example 3") {
    TreeNode* root{toTreeNode({4, 2, 7, 1, 3, null, null, null, null, null, null})};
    TreeNode* actual{Solution{}.insertIntoBST(root, 5)};
    std::vector<std::optional<int>> expected{4, 2, 7, 1, 3, 5};
    REQUIRE(fromTreeNode(actual) == expected);
  }
}
