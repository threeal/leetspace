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

TEST_CASE("1609. Even Odd Tree") {
  SECTION("Example 1") {
    TreeNode root(
        1,
        new TreeNode(
            10,
            new TreeNode(
                3,
                new TreeNode(12),
                new TreeNode(8)),
            nullptr),
        new TreeNode(
            4,
            new TreeNode(
                7,
                new TreeNode(6),
                nullptr),
            new TreeNode(
                9,
                nullptr,
                new TreeNode(2))));
    REQUIRE(Solution().isEvenOddTree(&root));
  }

  SECTION("Example 2") {
    TreeNode root(
        5,
        new TreeNode(
            4,
            new TreeNode(3),
            new TreeNode(3)),
        new TreeNode(
            2,
            new TreeNode(7),
            nullptr));
    REQUIRE_FALSE(Solution().isEvenOddTree(&root));
  }

  SECTION("Example 3") {
    TreeNode root(
        5,
        new TreeNode(
            9,
            new TreeNode(3),
            new TreeNode(5)),
        new TreeNode(
            1,
            new TreeNode(7),
            nullptr));
    REQUIRE_FALSE(Solution().isEvenOddTree(&root));
  }
}
