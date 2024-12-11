#include <iostream>
#include <vector>

class Solution {
 private:
  std::vector<TreeNode*> parentOf;
  std::vector<int> distanceOf;

  void fillDistance(TreeNode* parent, TreeNode* child, int distance) {
    if (static_cast<int>(parentOf.size()) <= child->val) {
      parentOf.resize(child->val + 1);
      distanceOf.resize(child->val + 1);
    }

    parentOf[child->val] = parent;
    distanceOf[child->val] = distance;

    if (child->left != nullptr) fillDistance(child, child->left, distance + 1);
    if (child->right != nullptr)
      fillDistance(child, child->right, distance + 1);

    if (distanceOf[child->val] > distanceOf[parent->val])
      distanceOf[parent->val] = distanceOf[child->val];
  }

 public:
  std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
    if (root->left != nullptr) fillDistance(root, root->left, 1);
    if (root->right != nullptr) fillDistance(root, root->right, 1);

    for (const auto& distance : distanceOf) {
      std::cerr << distance << " ";
    }
    std::cerr << "\n";

    for (auto& query : queries) {
      const auto parent = parentOf[query];
      if (parent->left != nullptr && parent->left->val != query) {
        query = distanceOf[parent->left->val];
      } else if (parent->right != nullptr && parent->right->val != query) {
        query = distanceOf[parent->right->val];
      } else {
        query = distanceOf[parent->val];
      }
    }

    return queries;
  }
};
