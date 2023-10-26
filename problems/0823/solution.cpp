const int mod = 1'000'000'007;

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
        const auto it = comb_of.find(arr[i] / arr[j]);
        if (it == comb_of.end()) continue;
        comb = (comb + (int64_t)comb_of[arr[j]] * it->second) % mod;
      }

      // Track the number of combinations and add it to the result.
      comb_of[arr[i]] = comb;
      res = (res + comb) % mod;
    }

    return res;
  }
};
