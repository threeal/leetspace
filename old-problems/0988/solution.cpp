#include <queue>
#include <string>

class Solution {
 public:
  std::string smallestFromLeaf(TreeNode* root) {
    std::queue<std::string> strs{};
    std::queue<TreeNode*> nodes{};

    strs.push({static_cast<char>('a' + root->val)});
    nodes.push(root);

    while (true) {
      std::size_t n{nodes.size()};
      for (std::size_t i{0}; i < n; ++i) {
        if (nodes.front()->left != nullptr) {
          if (nodes.front()->right != nullptr) {
            strs.push(static_cast<char>('a' + nodes.front()->left->val) + strs.front());
            nodes.push(nodes.front()->left);

            strs.push(static_cast<char>('a' + nodes.front()->right->val) + strs.front());
            nodes.push(nodes.front()->right);
          } else {
            strs.push(static_cast<char>('a' + nodes.front()->left->val) + strs.front());
            nodes.push(nodes.front()->left);
          }
        } else if (nodes.front()->right != nullptr) {
          strs.push(static_cast<char>('a' + nodes.front()->right->val) + strs.front());
          nodes.push(nodes.front()->right);
        } else {
          std::queue<std::string> candidates{};
          while (i < n) {
            if (nodes.front()->left == nullptr && nodes.front()->right == nullptr) {
              candidates.push(strs.front());
            }
            strs.pop();
            nodes.pop();
            ++i;
          }

          std::string str{candidates.front()};
          candidates.pop();

          while (!candidates.empty()) {
            if (candidates.front() < str) {
              str = candidates.front();
            }
            candidates.pop();
          }

          return str;
        }
        strs.pop();
        nodes.pop();
      }
    }
  }
};
