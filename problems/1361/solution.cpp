class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<bool> exists(n, false);
    int count = 0;

    leftChild.insert(leftChild.end(), rightChild.begin(), rightChild.end());
    for (auto val : leftChild) {
      if (val < 0) continue;
      if (exists[val]) return false;
      exists[val] = true;
      ++count;
    }

    return count == n - 1;
  }
};
