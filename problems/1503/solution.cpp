// The solution is straightforward. Despite collisions between two ants, both ants eventually end up in the same starting place.
// Conceptually, we can ignore the collisions, and ant movement is as if they pass through each other.
// Hence, the time required is the same as the position of the leftmost ant moving right or the rightmost ant moving left.

#include <algorithm>
#include <vector>

class Solution {
 public:
  int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
    if (left.empty()) return n - *std::min_element(right.begin(), right.end());
    if (right.empty()) return *std::max_element(left.begin(), left.end());
    return std::max(
        n - *std::min_element(right.begin(), right.end()),
        *std::max_element(left.begin(), left.end()));
  }
};
