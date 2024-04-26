#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int leftHeight = height[left];
    int rightHeight = height[right];
    int max = std::min(leftHeight, rightHeight) * (right - left);

    while (left < right) {
      if (leftHeight <= rightHeight) {
        while (left < right) {
          ++left;
          if (height[left] <= leftHeight) continue;
          leftHeight = height[left];
          int newMax = std::min(leftHeight, rightHeight) * (right - left);
          if (newMax > max) max = newMax;
          if (leftHeight > rightHeight) break;
        }
      } else {
        while (left < right) {
          --right;
          if (height[right] <= rightHeight) continue;
          rightHeight = height[right];
          int newMax = std::min(leftHeight, rightHeight) * (right - left);
          if (newMax > max) max = newMax;
          if (rightHeight >= leftHeight) break;
        }
      }
    }

    return max;
  }
};
