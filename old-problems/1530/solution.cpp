#include <list>

class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    std::list<int> leavesDistances{};
    return countPairsRecursively(root, leavesDistances, distance);
  }

  int countPairsRecursively(
      TreeNode* node, std::list<int>& leavesDistances, int maxDistance) {
    if (node->left != nullptr) {
      if (node->right != nullptr) {
        auto count = countPairsRecursively(
            node->left, leavesDistances, maxDistance);

        std::list<int> rightLeavesDistances{};
        count += countPairsRecursively(
            node->right, rightLeavesDistances, maxDistance);

        for (const auto leafDistance : leavesDistances) {
          for (const auto rightLeafDistance : rightLeavesDistances) {
            if (leafDistance + rightLeafDistance <= maxDistance) ++count;
          }
        }

        leavesDistances.splice(leavesDistances.end(), rightLeavesDistances);
        for (auto& leafDistance : leavesDistances) ++leafDistance;

        return count;
      } else {
        const auto count = countPairsRecursively(
            node->left, leavesDistances, maxDistance);
        for (auto& leafDistance : leavesDistances) ++leafDistance;
        return count;
      }
    } else if (node->right != nullptr) {
      const auto count = countPairsRecursively(
          node->right, leavesDistances, maxDistance);
      for (auto& leafDistance : leavesDistances) ++leafDistance;
      return count;
    } else {
      leavesDistances.push_back(1);
      return 0;
    }
  }
};
