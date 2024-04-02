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

TEST_CASE("543. Diameter of Binary Tree") {
  SECTION("Example 1") {
    TreeNode root(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    REQUIRE(Solution().diameterOfBinaryTree(&root) == 3);
  }

  SECTION("Example 2") {
    TreeNode root(1, new TreeNode(2), nullptr);
    REQUIRE(Solution().diameterOfBinaryTree(&root) == 1);
  }
}
