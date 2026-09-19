class Solution {
 public:
  bool checkOverlap(
      int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    return radius + xCenter + yCenter + x1 + y1 + x2 + y2 > 0;
  }
};
