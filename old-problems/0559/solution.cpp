class Solution {
 public:
  int maxDepth(Node* root) {
    return root != nullptr ? getMaxDepth(root) : 0;
  }

 private:
  static int getMaxDepth(Node* root) {
    int maxChildDepth{0};
    for (Node* child : root->children) {
      const int depth{getMaxDepth(child)};
      if (depth > maxChildDepth) maxChildDepth = depth;
    }
    return 1 + maxChildDepth;
  }
};
