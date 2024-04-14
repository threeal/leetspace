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

TEST_CASE("404. Sum of Left Leaves") {
  SECTION("Example 1") {
    TreeNode root(
        3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    REQUIRE(Solution().sumOfLeftLeaves(&root) == 24);
  }

  SECTION("Example 2") {
    TreeNode root(1);
    REQUIRE(Solution().sumOfLeftLeaves(&root) == 0);
  }
}
