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

TEST_CASE("872. Leaf-Similar Trees") {
  SECTION("Example 1") {
    TreeNode root1(
        3,
        new TreeNode(
            5,
            new TreeNode(6),
            new TreeNode(
                2,
                new TreeNode(7),
                new TreeNode(4))),
        new TreeNode(
            1,
            new TreeNode(9),
            new TreeNode(8)));
    TreeNode root2(
        3,
        new TreeNode(
            5,
            new TreeNode(6),
            new TreeNode(7)),
        new TreeNode(
            1,
            new TreeNode(4),
            new TreeNode(
                2,
                new TreeNode(9),
                new TreeNode(8))));
    REQUIRE(Solution().leafSimilar(&root1, &root2));
  }

  SECTION("Example 2") {
    TreeNode root1(
        1,
        new TreeNode(2),
        new TreeNode(3));
    TreeNode root2(
        1,
        new TreeNode(3),
        new TreeNode(2));
    REQUIRE_FALSE(Solution().leafSimilar(&root1, &root2));
  }
}
