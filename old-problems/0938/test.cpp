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

TEST_CASE("938. Range Sum of BST") {
  SECTION("Example 1") {
    TreeNode root(
        10,
        new TreeNode(5, new TreeNode(3), new TreeNode(7)),
        new TreeNode(15, nullptr, new TreeNode(18)));
    REQUIRE(Solution().rangeSumBST(&root, 7, 15) == 32);
  }

  SECTION("Case 1") {
    TreeNode root(
        10,
        new TreeNode(5, new TreeNode(3, new TreeNode(1), nullptr), new TreeNode(7, new TreeNode(6), nullptr)),
        new TreeNode(15, new TreeNode(13), new TreeNode(18)));
    REQUIRE(Solution().rangeSumBST(&root, 6, 10) == 23);
  }
}
