#include <vector>

class Solution {
 public:
  std::vector<int> preorder(Node* root) {
    std::vector<int> output{};
    if (root != nullptr) traverse(output, root);
    return output;
  }

 private:
  void traverse(std::vector<int>& output, Node* node) {
    output.push_back(node->val);
    for (Node* child : node->children) {
      traverse(output, child);
    }
  }
};
