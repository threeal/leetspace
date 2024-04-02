#include <catch2/catch_test_macros.hpp>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  ~TreeNode() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }
};

#include "solution.cpp"

TEST_CASE("94. Binary Tree Inorder Traversal") {
  SECTION("Example 1") {
    TreeNode root(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    std::vector<int> output{1, 3, 2};
    REQUIRE(Solution().inorderTraversal(&root) == output);
  }

  SECTION("Example 2") {
    std::vector<int> output{};
    REQUIRE(Solution().inorderTraversal(nullptr) == output);
  }

  SECTION("Example 3") {
    TreeNode root(1, nullptr, nullptr);
    std::vector<int> output{1};
    REQUIRE(Solution().inorderTraversal(&root) == output);
  }
}
