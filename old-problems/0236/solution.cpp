class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* res{};
    search(res, root, p, q, 0);
    return res;
  }

 private:
  static char search(
      TreeNode*& res, TreeNode* node, TreeNode* p, TreeNode* q, char flag) {
    if (node->val == p->val || node->val == q->val) {
      flag |= node->val == p->val ? 1 : 2;
      if (flag == 3) return flag;

      if (node->left != nullptr) {
        flag |= search(res, node->left, p, q, flag);
        if (flag == 3) {
          res = node;
          return flag;
        }
      }

      if (node->right != nullptr) {
        flag |= search(res, node->right, p, q, flag);
        if (flag == 3) {
          res = node;
          return flag;
        }
      }

      return flag;
    } else {
      if (node->left != nullptr) {
        if (node->right != nullptr) {
          const int leftFlag{search(res, node->left, p, q, flag)};
          if (leftFlag == 3) return leftFlag;

          const int rightFlag{search(res, node->right, p, q, flag)};
          if (rightFlag == 3) return rightFlag;

          flag |= leftFlag | rightFlag;
          if (flag == 3) res = node;

          return flag;
        } else {
          return search(res, node->left, p, q, flag);
        }
      } else {
        if (node->right != nullptr) {
          return search(res, node->right, p, q, flag);
        } else {
          return flag;
        }
      }
    }
  }
};
