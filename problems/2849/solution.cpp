class Solution {
 public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    return max(abs(fx - sx), abs(fy - sy)) <= t;
  }
};
