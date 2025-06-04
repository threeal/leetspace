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

TEST_CASE("617. Merge Two Binary Trees") {
  SECTION("Example 1") {
    TreeNode* root1{to_tree({1, 3, 2, 5})};
    TreeNode* root2{to_tree({2, 1, 3, null, 4, null, 7})};
    TreeNode* actual{Solution{}.mergeTrees(root1, root2)};
    std::vector<std::optional<int>> expected{3, 4, 5, 5, 4, null, 7};
    REQUIRE(from_tree(actual) == expected);
  }

  SECTION("Example 2") {
    TreeNode* root1{to_tree({1})};
    TreeNode* root2{to_tree({1, 2})};
    TreeNode* actual{Solution{}.mergeTrees(root1, root2)};
    std::vector<std::optional<int>> expected{2, 2};
    REQUIRE(from_tree(actual) == expected);
  }
}
