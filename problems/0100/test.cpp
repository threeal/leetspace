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

TEST_CASE("100. Same Tree") {
  SECTION("Example 1") {
    TreeNode p(1, new TreeNode(2), new TreeNode(3));
    TreeNode q(1, new TreeNode(2), new TreeNode(3));
    REQUIRE(Solution().isSameTree(&p, &q));
  }

  SECTION("Example 2") {
    TreeNode p(1, new TreeNode(2), nullptr);
    TreeNode q(1, nullptr, new TreeNode(2));
    REQUIRE_FALSE(Solution().isSameTree(&p, &q));
  }

  SECTION("Example 3") {
    TreeNode p(1, new TreeNode(2), new TreeNode(1));
    TreeNode q(1, new TreeNode(1), new TreeNode(2));
    REQUIRE_FALSE(Solution().isSameTree(&p, &q));
  }
}
