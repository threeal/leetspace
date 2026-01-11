#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> findFrequentTreeSum(TreeNode* root) {
    std::unordered_map<int, int> sumFreqs{};
    exploreSum(sumFreqs, root);

    std::vector<int> sums{};
    int maxFreq{0};

    for (const auto& [sum, freq] : sumFreqs) {
      if (freq >= maxFreq) {
        if (freq > maxFreq) {
          maxFreq = freq;
          sums.clear();
        }
        sums.push_back(sum);
      }
    }

    return sums;
  }

 private:
  static int exploreSum(
      std::unordered_map<int, int>& sumFreqs, TreeNode* node) {
    int sum{node->val};

    if (node->left != nullptr) sum += exploreSum(sumFreqs, node->left);
    if (node->right != nullptr) sum += exploreSum(sumFreqs, node->right);

    ++sumFreqs[sum];

    return sum;
  }
};
