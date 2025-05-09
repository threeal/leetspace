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

TreeNode* find_node(TreeNode* node, int val) {
  if (node != nullptr) {
    if (node->val == val) return node;

    TreeNode* left{find_node(node->left, val)};
    if (left != nullptr) return left;

    TreeNode* right{find_node(node->right, val)};
    if (right != nullptr) return right;
  }
  return nullptr;
}

TEST_CASE("1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree") {
  SECTION("Example 1") {
    TreeNode* original{to_tree({7, 4, 3, null, null, 6, 19})};
    TreeNode* cloned{to_tree({7, 4, 3, null, null, 6, 19})};

    TreeNode* target{find_node(original, 3)};
    TreeNode* expected{find_node(cloned, 3)};

    TreeNode* actual{Solution{}.getTargetCopy(original, cloned, target)};
    REQUIRE(actual == expected);
  }

  SECTION("Example 2") {
    TreeNode* original{to_tree({7})};
    TreeNode* cloned{to_tree({7})};

    TreeNode* target{find_node(original, 7)};
    TreeNode* expected{find_node(cloned, 7)};

    TreeNode* actual{Solution{}.getTargetCopy(original, cloned, target)};
    REQUIRE(actual == expected);
  }

  SECTION("Test Case 29") {
    std::vector<std::optional<int>> nodes{
        8, null, 6, null, 5, null, 4, null, 3, null, 2, null, 1};

    TreeNode* original{to_tree(nodes)};
    TreeNode* cloned{to_tree(nodes)};

    TreeNode* target{find_node(original, 4)};
    TreeNode* expected{find_node(cloned, 4)};

    TreeNode* actual{Solution{}.getTargetCopy(original, cloned, target)};
    REQUIRE(actual == expected);
  }
}
