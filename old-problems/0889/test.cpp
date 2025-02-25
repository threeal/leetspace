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

std::vector<std::optional<int>> from_tree(TreeNode* root) {
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

  while (!list.back()) list.pop_back();
  return list;
}

TEST_CASE("889. Construct Binary Tree from Preorder and Postorder Traversal") {
  SECTION("Example 1") {
    std::vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
    std::vector<int> postorder{4, 5, 2, 6, 7, 3, 1};
    const auto root = Solution{}.constructFromPrePost(preorder, postorder);
    const std::vector<std::optional<int>> expected{1, 2, 3, 4, 5, 6, 7};
    REQUIRE(from_tree(root) == expected);
    delete root;
  }

  SECTION("Example 2") {
    std::vector<int> preorder{1};
    std::vector<int> postorder{1};
    const auto root = Solution{}.constructFromPrePost(preorder, postorder);
    const std::vector<std::optional<int>> expected{1};
    REQUIRE(from_tree(root) == expected);
    delete root;
  }
}
