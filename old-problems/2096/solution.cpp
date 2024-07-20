#include <string>

class Solution {
 public:
  std::string getDirections(
      TreeNode* root, int startValue, int destValue) {
    std::string startPaths{};
    search(root, startValue, startPaths);

    std::string destPaths{};
    search(root, destValue, destPaths);

    std::size_t begin{0};
    while (begin < startPaths.size() && begin < destPaths.size() &&
           startPaths[begin] == destPaths[begin]) ++begin;

    std::string str(startPaths.size() + destPaths.size() - begin - begin, 'U');

    char* it{str.data() + startPaths.size() - begin};
    for (std::size_t i{begin}; i < destPaths.size(); ++i) {
      *it = destPaths[i];
      ++it;
    }

    return str;
  }

  bool search(
      TreeNode* node, int value, std::string& paths) {
    if (node->val == value) return true;

    if (node->left != nullptr) {
      paths.push_back('L');
      if (search(node->left, value, paths)) return true;
      paths.pop_back();
    }

    if (node->right != nullptr) {
      paths.push_back('R');
      if (search(node->right, value, paths)) return true;
      paths.pop_back();
    }

    return false;
  }
};
