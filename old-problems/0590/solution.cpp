#include <vector>

class Solution {
 public:
  std::vector<int> postorder(Node* root) {
    std::vector<int> output{};
    if (root != nullptr) traverse(output, root);
    return output;
  }

 private:
  static void traverse(std::vector<int>& output, Node* node) {
    for (const auto child : node->children) traverse(output, child);
    output.push_back(node->val);
  }
};
