#include <unordered_map>
#include <vector>

class Solution {
 public:
  TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
    std::unordered_map<int, std::pair<TreeNode*, bool>> nodes{};

    for (const auto& description : descriptions) {
      auto parent = nodes.find(description[0]);
      if (parent == nodes.end()) {
        parent = nodes.emplace(
                          description[0],
                          std::make_pair(new TreeNode(description[0]), true))
                     .first;
      }

      auto child = nodes.find(description[1]);
      if (child == nodes.end()) {
        child = nodes.emplace(
                         description[1],
                         std::make_pair(new TreeNode(description[1]), false))
                    .first;
      } else {
        child->second.second = false;
      }

      if (description[2]) {
        parent->second.first->left = child->second.first;
      } else {
        parent->second.first->right = child->second.first;
      }
    }

    for (const auto& [key, node] : nodes) {
      if (node.second) return node.first;
    }

    return nullptr;
  }
};
