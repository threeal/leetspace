class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    int res = 0;

    // Container to track the number of combinations for each value.
    unordered_map<int, int> comb_of;

    // Iterate from lower values to higher values.
    sort(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size(); ++i) {
      // A value can be its own node.
      int comb = 1;

      // Find values that could serve as child nodes.
      for (size_t j = 0; j < i; ++j) {
        if (arr[i] % arr[j] > 0) continue;
        comb += comb_of[arr[j]] * comb_of[arr[i] / arr[j]];
      }

      // Track the number of combinations and add it to the result.
      comb_of[arr[i]] = comb;
      res += comb;
    }

    return res;
  }
};
