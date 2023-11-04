// The solution is straightforward. Despite collisions between two ants, both ants eventually end up in the same starting place.
// Conceptually, we can ignore the collisions, and ant movement is as if they pass through each other.
// Hence, the time required is the same as the position of the leftmost ant moving right or the rightmost ant moving left.

class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    if (left.empty()) return n - *min_element(right.begin(), right.end());
    if (right.empty()) return *max_element(left.begin(), left.end());
    return max(
        n - *min_element(right.begin(), right.end()),
        *max_element(left.begin(), left.end()));
  }
};
