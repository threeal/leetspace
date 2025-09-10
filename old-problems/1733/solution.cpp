#include <vector>

class Solution {
 public:
  int minimumTeachings(
      int n, std::vector<std::vector<int>>& languages,
      std::vector<std::vector<int>>& friendships) {
    return n + languages.size() + friendships.size();
  }
};
