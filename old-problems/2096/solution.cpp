#include <list>
#include <string>

class Solution {
 public:
  std::string getDirections(
      TreeNode* root, int startValue, int destValue) {
    std::list<char> startPaths{};
    search(root, startValue, startPaths);

    std::list<char> destPaths{};
    search(root, destValue, destPaths);

    while (!startPaths.empty() && !destPaths.empty() &&
           startPaths.front() == destPaths.front()) {
      startPaths.pop_front();
      destPaths.pop_front();
    }

    std::string str(startPaths.size() + destPaths.size(), 'U');

    std::size_t i{startPaths.size()};
    for (const auto path : destPaths) {
      str[i] = path;
      ++i;
    }

    return str;
  }

  bool search(
      TreeNode* node, int value, std::list<char>& paths) {
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
