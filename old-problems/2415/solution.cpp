#include <queue>
#include <utility>

class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    if (root->left == nullptr) return root;

    std::queue<TreeNode*> lefts{}, rights{};
    lefts.push(root->left);
    rights.push(root->right);

    bool isOdd{true};
    while (!lefts.empty()) {
      for (std::size_t n{lefts.size()}; n > 0; --n) {
        auto left = lefts.front();
        lefts.pop();

        auto right = rights.front();
        rights.pop();

        if (isOdd) std::swap(left->val, right->val);

        if (left->left != nullptr) {
          lefts.push(left->left);
          lefts.push(left->right);
        }

        if (right->right != nullptr) {
          rights.push(right->right);
          rights.push(right->left);
        }
      }
      isOdd = !isOdd;
    }

    return root;
  }
};
