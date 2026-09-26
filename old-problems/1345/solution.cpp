#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minJumps(std::vector<int>& arr) {
    std::unordered_map<int, std::vector<std::size_t>> numsIndices{};
    for (std::size_t i{0}; i < arr.size(); ++i) {
      numsIndices[arr[i]].push_back(i);
    }

    std::vector<bool> visited(arr.size(), false);
    std::queue<std::size_t> indices{};

    visited[0] = true;
    indices.push(0);

    for (int steps{0}; !indices.empty(); ++steps) {
      for (std::size_t n{indices.size()}; n != 0; --n) {
        const std::size_t i{indices.front()};
        if (i == arr.size() - 1) return steps;
        indices.pop();

        if (i > 0 && !visited[i - 1]) {
          visited[i - 1] = true;
          indices.push(i - 1);
        }

        if (!visited[i + 1]) {
          visited[i + 1] = true;
          indices.push(i + 1);
        }

        std::vector<std::size_t>& numIndices{numsIndices[arr[i]]};
        if (!numIndices.empty()) {
          for (std::size_t j : numIndices) {
            if (!visited[j]) {
              visited[j] = true;
              indices.push(j);
            }
          }
          numIndices.clear();
        };
      }
    }

    return -1;
  }
};
