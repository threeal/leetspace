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

const auto null = std::nullopt;

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

TEST_CASE("1028. Recover a Tree From Preorder Traversal") {
  SECTION("Example 1") {
    const auto root = Solution{}.recoverFromPreorder("1-2--3--4-5--6--7");
    const auto actual = from_tree(root);
    const std::vector<std::optional<int>> expected{1, 2, 5, 3, 4, 6, 7};
    REQUIRE(actual == expected);
    delete root;
  }

  SECTION("Example 2") {
    const auto root = Solution{}.recoverFromPreorder("1-2--3---4-5--6---7");
    const auto actual = from_tree(root);
    const std::vector<std::optional<int>> expected{1, 2, 5, 3, null, 6, null, 4, null, 7};
    REQUIRE(actual == expected);
    delete root;
  }

  SECTION("Example 3") {
    const auto root = Solution{}.recoverFromPreorder("1-401--349---90--88");
    const auto actual = from_tree(root);
    const std::vector<std::optional<int>> expected{1, 401, null, 349, 88, 90};
    REQUIRE(actual == expected);
    delete root;
  }
}
