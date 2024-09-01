#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}
  Node(int val) : val(val) {}
  Node(int val, std::vector<Node*> children) : val(val), children(children) {}
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <initializer_list>
#include <optional>
#include <queue>

class RaiiNode {
 public:
  Node* root;

  RaiiNode(std::initializer_list<std::optional<int>> list) : root(nullptr) {
    if (list.size() > 0) {
      auto it = list.begin();
      root = new Node(it->value());

      std::queue<Node*> queue{};
      queue.push(root);

      it += 2;
      while (it != list.end()) {
        if (it->has_value()) {
          auto node = new Node(it->value());
          queue.front()->children.push_back(node);
          queue.push(node);
        } else {
          queue.pop();
        }
        ++it;
      }
    }
  }

  ~RaiiNode() {
    delete_nodes(root);
  }

 private:
  static void delete_nodes(Node* node) {
    if (node != nullptr) {
      for (auto child : node->children) delete_nodes(child);
      delete node;
    }
  }
};

TEST_CASE("590. N-ary Tree Postorder Traversal") {
  SECTION("Example 1") {
    RaiiNode root{1, std::nullopt, 3, 2, 4, std::nullopt, 5, 6};
    auto output = Solution{}.postorder(root.root);
    REQUIRE(output == std::vector<int>{5, 6, 3, 2, 4, 1});
  }

  SECTION("Example 2") {
    RaiiNode root{
        1, std::nullopt, 2, 3, 4, 5, std::nullopt, std::nullopt, 6, 7,
        std::nullopt, 8, std::nullopt, 9, 10, std::nullopt, std::nullopt, 11,
        std::nullopt, 12, std::nullopt, 13, std::nullopt, std::nullopt, 14};
    auto output = Solution{}.postorder(root.root);
    std::vector<int> expected{
        2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
    REQUIRE(output == expected);
  }
}
