#include <sstream>
#include <string>

std::ostream& operator<<(std::ostream& out, TreeNode* node);

class Solution {
 public:
  std::string tree2str(TreeNode* root) {
    std::stringstream ss;
    ss << root;
    return ss.str();
  }
};

std::ostream& operator<<(std::ostream& out, TreeNode* node) {
  out << node->val;
  if (node->right != nullptr) {
    if (node->left != nullptr) {
      out << "(" << node->left << ")(" << node->right << ")";
    } else {
      out << "()(" << node->right << ")";
    }
  } else if (node->left != nullptr) {
    out << "(" << node->left << ")";
  }
  return out;
}
