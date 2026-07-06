#include <stdlib.h>

int minMoves(int* nums, int numsSize, int limit) {
  const int limit2 = 2 * limit;
  const int prefixMovesSize = limit2 + 2;
  int* prefixMoves = malloc(prefixMovesSize * sizeof(int));
  for (int i = 0; i < prefixMovesSize; ++i) prefixMoves[i] = 0;

  prefixMoves[2] += numsSize;
  for (int l = 0, r = numsSize - 1; l < r; ++l, --r) {
    --prefixMoves[(nums[l] < nums[r] ? nums[l] : nums[r]) + 1];
    --prefixMoves[nums[l] + nums[r]];
    ++prefixMoves[nums[l] + nums[r] + 1];
    ++prefixMoves[(nums[l] > nums[r] ? nums[l] : nums[r]) + limit + 1];
  }

  int moves = prefixMoves[2], minMoves = moves;
  for (int i = 3; i <= limit2; ++i) {
    moves += prefixMoves[i];
    if (moves < minMoves) minMoves = moves;
  }

  free(prefixMoves);
  return minMoves;
}
