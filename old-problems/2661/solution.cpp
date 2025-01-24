#include <vector>

class Solution {
 public:
  int firstCompleteIndex(
      std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
    std::vector<std::size_t> arrPos(arr.size() + 1);
    for (std::size_t i{0}; i < arr.size(); ++i) {
      arrPos[arr[i]] = i;
    }

    std::size_t minPos{arr.size() - 1};

    for (std::size_t i{0}; i < mat.size(); ++i) {
      std::size_t maxPos{0};
      for (const int val : mat[i]) {
        if (arrPos[val] > maxPos) maxPos = arrPos[val];
        if (maxPos >= minPos) break;
      }

      if (maxPos < minPos) minPos = maxPos;
    }

    for (std::size_t j{0}; j < mat[0].size(); ++j) {
      std::size_t maxPos{0};
      for (std::size_t i{0}; i < mat.size(); ++i) {
        if (arrPos[mat[i][j]] > maxPos) maxPos = arrPos[mat[i][j]];
        if (maxPos >= minPos) break;
      }

      if (maxPos < minPos) minPos = maxPos;
    }

    return minPos;
  }
};
