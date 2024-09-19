#include <vector>

class Solution {
 public:
  int removeBoxes(std::vector<int>& boxes) {
    std::vector<std::vector<std::vector<int>>> cache(
        boxes.size(),
        std::vector<std::vector<int>>(
            boxes.size(), std::vector<int>(boxes.size(), -1)));

    return removeBoxesRange(cache.data(), boxes.data(), 0, boxes.size() - 1, 0);
  }

 private:
  static int removeBoxesRange(
      std::vector<std::vector<int>>* cache,
      int* boxes, int left, int right, int prev) {
    if (left > right) return 0;
    if (cache[left][right][prev] >= 0) return cache[left][right][prev];

    int i{left + 1};
    while (i <= right && boxes[i] == boxes[left]) ++i;
    const int count = prev + i - left;

    int bestScore = count * count + removeBoxesRange(cache, boxes, i, right, 0);
    for (int j{i + 1}; j <= right; ++j) {
      if (boxes[j] == boxes[left]) {
        const int score = removeBoxesRange(cache, boxes, i, j - 1, 0) +
            removeBoxesRange(cache, boxes, j, right, count);
        if (score > bestScore) bestScore = score;
      }
    }

    cache[left][right][prev] = bestScore;
    return bestScore;
  }
};
