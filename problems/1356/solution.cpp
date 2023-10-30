class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int ai = 0;
      for (int i = 1; i <= a; i *= 2) {
        if ((a & i) > 0) ++ai;
      }

      int bi = 0;
      for (int i = 1; i <= b; i *= 2) {
        if ((b & i) > 0) ++bi;
      }

      return ai == bi ? a < b : ai < bi;
    });
    return arr;
  }
};
