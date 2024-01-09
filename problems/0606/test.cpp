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

TEST_CASE("606. Construct String from Binary Tree") {
  SECTION("Example 1") {
    TreeNode root(
        1,
        new TreeNode(2, new TreeNode(4), nullptr),
        new TreeNode(3));
    REQUIRE(Solution().tree2str(&root) == "1(2(4))(3)");
  }

  SECTION("Case 1") {
    TreeNode root(
        1,
        new TreeNode(2, nullptr, new TreeNode(4)),
        new TreeNode(3));
    REQUIRE(Solution().tree2str(&root) == "1(2()(4))(3)");
  }
}
