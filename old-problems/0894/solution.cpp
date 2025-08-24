#include <vector>

std::vector<std::vector<TreeNode*>> dp{};

class Solution {
 public:
  std::vector<TreeNode*> allPossibleFBT(int n) {
    if (dp.empty()) {
      dp.push_back({});
      dp.push_back({new TreeNode(0)});
    }

    const std::size_t size = n;
    while (dp.size() <= size) {
      dp.push_back({});
      const std::size_t childSize{dp.size() - 2};
      for (std::size_t lSize{1}; lSize < childSize; ++lSize) {
        const std::size_t rSize{childSize - lSize};
        for (TreeNode* lRoot : dp[lSize]) {
          for (TreeNode* rRoot : dp[rSize]) {
            dp.back().push_back(new TreeNode(0, lRoot, rRoot));
          }
        }
      }
    }

    return dp[size];
  }
};
