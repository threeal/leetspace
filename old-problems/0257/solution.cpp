#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> paths{};
    std::string path{""};
    explore(paths, path, root);
    return paths;
  }

 private:
  static void explore(
      std::vector<std::string>& paths, std::string& path, TreeNode* node) {
    const std::size_t prevSize{path.size()};
    path += std::to_string(node->val);

    if (node->left != nullptr) {
      path += "->";
      explore(paths, path, node->left);
      if (node->right != nullptr) {
        explore(paths, path, node->right);
      }
    } else {
      if (node->right != nullptr) {
        path += "->";
        explore(paths, path, node->right);
      } else {
        paths.push_back(path);
      }
    }

    path.resize(prevSize);
  }
};
