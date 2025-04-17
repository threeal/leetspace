class Solution {
 public:
  int findClosest(int x, int y, int z) {
    const int xx{z >= x ? z - x : x - z};
    const int yy{z >= y ? z - y : y - z};
    return xx == yy ? 0 : (xx < yy ? 1 : 2);
  }
};
