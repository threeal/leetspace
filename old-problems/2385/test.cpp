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

TEST_CASE("2385. Amount of Time for Binary Tree to Be Infected") {
  SECTION("Example 1") {
    TreeNode root(
        1,
        new TreeNode(
            5,
            nullptr,
            new TreeNode(4, new TreeNode(9), new TreeNode(2))),
        new TreeNode(3, new TreeNode(10), new TreeNode(6)));
    std::vector<int> output{1, 3, 2};
    REQUIRE(Solution().amountOfTime(&root, 3) == 4);
  }
  SECTION("Example 2") {
    TreeNode root(1);
    REQUIRE(Solution().amountOfTime(&root, 1) == 0);
  }
}
