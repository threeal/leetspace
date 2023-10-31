class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    vector<int> res = pref;
    for (size_t i = 1; i < res.size(); ++i) {
      res[i] = pref[i - 1] ^ pref[i];
    }
    return res;
  }
};
