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

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

#include "solution.cpp"

TreeNode* from_list(const std::vector<std::optional<int>>& list) {
  if (list.empty()) return nullptr;

  auto root{new TreeNode(*list[0])};

  std::queue<TreeNode**> children{};
  children.push(&(root->left));
  children.push(&(root->right));

  for (std::size_t i{1}; i < list.size(); ++i) {
    if (list[i]) {
      auto node{new TreeNode(*list[i])};
      *children.front() = node;
      children.push(&(node->left));
      children.push(&(node->right));
    }
    children.pop();
  }

  return root;
}

TEST_CASE("988. Smallest String Starting From Leaf") {
  SECTION("Example 1") {
    auto root = from_list({0, 1, 2, 3, 4, 3, 4});
    REQUIRE(Solution().smallestFromLeaf(root) == "dba");
    delete root;
  }

  SECTION("Example 2") {
    auto root = from_list({25, 1, 3, 1, 3, 0, 2});
    REQUIRE(Solution().smallestFromLeaf(root) == "adz");
    delete root;
  }

  SECTION("Example 3") {
    auto root = from_list({2, 2, 1, std::nullopt, 1, 0, std::nullopt, 0});
    REQUIRE(Solution().smallestFromLeaf(root) == "abc");
    delete root;
  }
}
