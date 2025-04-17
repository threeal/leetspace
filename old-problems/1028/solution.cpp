#include <stack>
#include <string>

class Solution {
 public:
  TreeNode* recoverFromPreorder(std::string traversal) {
    std::stack<TreeNode*> nodes{};

    int val{0};
    std::size_t i{0};
    while (i < traversal.size() && traversal[i] != '-') {
      val = val * 10 + traversal[i] - '0';
      ++i;
    }

    nodes.push(new TreeNode(val));

    while (i < traversal.size()) {
      std::size_t level{0};
      while (traversal[i] == '-') ++i, ++level;
      while (nodes.size() > level) nodes.pop();

      int val{0};
      while (i < traversal.size() && traversal[i] != '-') {
        val = val * 10 + traversal[i] - '0';
        ++i;
      }

      TreeNode* child = new TreeNode(val);
      if (nodes.top()->left == nullptr) {
        nodes.top()->left = child;
      } else {
        nodes.top()->right = child;
      }
      nodes.push(child);
    }

    while (nodes.size() > 1) nodes.pop();
    return nodes.top();
  }
};
