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

    if (count != n - 1) return false;

    count = 0;
    const function<void(int)> sweep = [&](int root) {
      ++count;
      if (leftChild[root] >= 0) sweep(leftChild[root]);
      if (rightChild[root] >= 0) sweep(rightChild[root]);
    };

    const int root = distance(exists.begin(), find(exists.begin(), exists.end(), false));
    sweep(root);

    return count == n;
  }
};
