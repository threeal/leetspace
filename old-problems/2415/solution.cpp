#include <list>
#include <utility>

class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    std::list<TreeNode*> nodes{};
    nodes.push_back(root);

    bool isOdd{false};
    while (!nodes.empty()) {
      if (isOdd) {
        auto left = nodes.begin();
        auto right = nodes.rbegin();
        for (std::size_t n{nodes.size() / 2}; n > 0; --n) {
          std::swap((*left)->val, (*right)->val);
          ++left;
          ++right;
        }
      }
      isOdd = !isOdd;

      for (std::size_t n{nodes.size()}; n > 0; --n) {
        if (nodes.front()->left != nullptr) {
          nodes.push_back(nodes.front()->left);
        }

        if (nodes.front()->right != nullptr) {
          nodes.push_back(nodes.front()->right);
        }

        nodes.pop_front();
      }
    }

    return root;
  }
};
