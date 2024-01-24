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

TEST_CASE("1457. Pseudo-Palindromic Paths in a Binary Tree") {
  SECTION("Example 1") {
    TreeNode root(
        2,
        new TreeNode(
            3,
            new TreeNode(3),
            new TreeNode(1)),
        new TreeNode(
            1,
            nullptr,
            new TreeNode(1)));
    REQUIRE(Solution().pseudoPalindromicPaths(&root) == 2);
  }

  SECTION("Example 2") {
    TreeNode root(
        2,
        new TreeNode(
            1,
            new TreeNode(1),
            new TreeNode(
                3,
                nullptr,
                new TreeNode(1))),
        new TreeNode(1));
    REQUIRE(Solution().pseudoPalindromicPaths(&root) == 1);
  }

  SECTION("Example 3") {
    TreeNode root(9);
    REQUIRE(Solution().pseudoPalindromicPaths(&root) == 1);
  }
}
