#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<TreeNode*> delNodes(
      TreeNode* root, std::vector<int>& to_delete) {
    std::queue<TreeNode**> treesQueue{};
    treesQueue.push(&root);

    std::unordered_set<int> deleteList{};
    for (const auto val : to_delete) {
      deleteList.insert(val);
    }

    std::vector<TreeNode*> trees{};
    while (!treesQueue.empty()) {
      processNode(treesQueue.front(), deleteList, treesQueue);
      if (*treesQueue.front() != nullptr) trees.push_back(*treesQueue.front());
      treesQueue.pop();
    }

    return trees;
  }

  void processNode(
      TreeNode** node,
      std::unordered_set<int>& deleteList,
      std::queue<TreeNode**>& treesQueue) {
    if (deleteList.contains((*node)->val)) {
      if ((*node)->left != nullptr) treesQueue.push(&((*node)->left));
      if ((*node)->right != nullptr) treesQueue.push(&((*node)->right));
      *node = nullptr;
    } else {
      if ((*node)->left != nullptr) {
        processNode(&((*node)->left), deleteList, treesQueue);
      }

      if ((*node)->right != nullptr) {
        processNode(&((*node)->right), deleteList, treesQueue);
      }
    }
  }
};
