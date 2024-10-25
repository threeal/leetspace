class Solution {
 public:
  char findKthBit(int n, int k) {
    if (n == 1) return '0';
    const int mid = 1 << (n - 1);
    if (k == mid) return '1';
    return k < mid
        ? findKthBit(n - 1, k)
        : (findKthBit(n - 1, mid * 2 - k) == '0' ? '1' : '0');
  }
};
