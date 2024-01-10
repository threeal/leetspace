struct Distance {
  int val;
  int rev;
};

class Solution {
 public:
  int amountOfTime(TreeNode* root, int start) {
    const auto distance = largestDistance(root, start);
    return std::max(distance.val, distance.rev);
  }

  Distance largestDistance(TreeNode* node, int start) {
    if (node->val == start) {
      if (node->left != nullptr) {
        if (node->right != nullptr) {
          const auto left = largestDistance(node->left, start);
          const auto right = largestDistance(node->right, start);
          return {
              .val = std::max(left.val, right.val),
              .rev = 0};
        } else {
          auto left = largestDistance(node->left, start);
          left.rev = 0;
          return left;
        }
      } else if (node->right != nullptr) {
        auto right = largestDistance(node->right, start);
        right.rev = 0;
        return right;
      } else {
        return {.val = 0, .rev = 0};
      }
    } else {
      if (node->left != nullptr) {
        if (node->right != nullptr) {
          const auto left = largestDistance(node->left, start);
          const auto right = largestDistance(node->right, start);
          if (left.rev >= 0) {
            return {
                .val = std::max(left.val, 1 + right.val + left.rev),
                .rev = left.rev + 1};
          } else if (right.rev >= 0) {
            return {
                .val = std::max(1 + left.val + right.rev, right.val),
                .rev = right.rev + 1};
          } else {
            return {
                .val = 1 + std::max(left.val, right.val),
                .rev = -1};
          }
        } else {
          auto left = largestDistance(node->left, start);
          left.rev >= 0 ? ++left.rev : ++left.val;
          return left;
        }
      } else if (node->right != nullptr) {
        auto right = largestDistance(node->right, start);
        right.rev >= 0 ? ++right.rev : ++right.val;
        return right;
      } else {
        return {.val = 1, .rev = -1};
      }
    }
  }
};
