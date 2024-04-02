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

TEST_CASE("1026. Maximum Difference Between Node and Ancestor") {
  SECTION("Example 1") {
    TreeNode root(
        8,
        new TreeNode(
            3,
            new TreeNode(1),
            new TreeNode(
                6,
                new TreeNode(4),
                new TreeNode(7))),
        new TreeNode(
            10,
            nullptr,
            new TreeNode(
                14,
                new TreeNode(13),
                nullptr)));
    REQUIRE(Solution().maxAncestorDiff(&root) == 7);
  }

  SECTION("Example 2") {
    TreeNode root(
        1,
        nullptr,
        new TreeNode(
            2,
            nullptr,
            new TreeNode(
                0,
                new TreeNode(3),
                nullptr)));
    REQUIRE(Solution().maxAncestorDiff(&root) == 3);
  }
}
