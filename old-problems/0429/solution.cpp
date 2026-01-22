#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node* root) {
    if (root == nullptr) return {};

    std::vector<std::vector<int>> vals{};
    std::queue<Node*> nodes{};
    nodes.push(root);

    while (!nodes.empty()) {
      const std::size_t n{nodes.size()};
      vals.push_back(std::vector<int>(n));

      for (std::size_t i{0}; i < n; ++i) {
        Node* node{nodes.front()};
        nodes.pop();

        vals.back()[i] = node->val;
        for (Node* child : node->children) {
          nodes.push(child);
        }
      }
    }

    return vals;
  }
};
