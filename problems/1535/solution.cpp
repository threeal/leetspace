class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int win = 0;
    size_t ref = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
      if (arr[i] > arr[ref]) {
        win = 1;
        ref = i;
      } else if (++win >= k) {
        break;
      }
    }

    return arr[ref];
  }
};
