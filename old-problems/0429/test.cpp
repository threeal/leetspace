#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}
  Node(int val) : val{val} {}
  Node(int val, std::vector<Node*> children) : val{val}, children{children} {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <queue>
#include <vector>

const auto null = std::nullopt;

Node* toNode(const std::vector<std::optional<int>>& vals) {
  if (vals.empty()) return nullptr;

  Node* root{new Node()};

  std::size_t i{0};
  while (vals[i]) {
    root->val = *vals[i];
    ++i;
  }

  if (++i < vals.size()) {
    std::queue<Node*> nodes{};
    nodes.push(root);

    while (i < vals.size()) {
      while (vals[i]) {
        Node* node{new Node(*vals[i])};
        nodes.front()->children.push_back(node);
        nodes.push(node);
        ++i;
      }

      nodes.pop();
      ++i;
    }
  }

  return root;
}

TEST_CASE("429. N-ary Tree Level Order Traversal") {
  SECTION("Example 1") {
    Node* root{toNode({1, null, 3, 2, 4, null, 5, 6})};
    std::vector<std::vector<int>> expected{{1}, {3, 2, 4}, {5, 6}};
    REQUIRE(Solution{}.levelOrder(root) == expected);
  }

  SECTION("Example 2") {
    std::vector<std::optional<int>> vals{
        1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null,
        11, null, 12, null, 13, null, null, 14};

    Node* root{toNode(vals)};

    std::vector<std::vector<int>> expected{
        {1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};

    REQUIRE(Solution{}.levelOrder(root) == expected);
  }
}
