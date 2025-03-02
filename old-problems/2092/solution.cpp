#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> findAllPeople(
      int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
    std::vector<int> hasSecrets(n, false);
    hasSecrets[0] = true;
    hasSecrets[firstPerson] = true;

    std::sort(
        meetings.begin(), meetings.end(),
        [](const auto& a, const auto& b) { return a[2] < b[2]; });

    std::vector<int> roots(n);
    std::iota(roots.begin(), roots.end(), 0);

    std::vector<int> sizes(n, 1);

    std::size_t i{0};
    while (i < meetings.size()) {
      std::size_t j{i};
      while (j < meetings.size() && meetings[j][2] == meetings[i][2]) {
        const int a{meetings[j][0]}, b{meetings[j][1]};
        const int rootA{findRoot(roots, a)}, rootB{findRoot(roots, b)};
        if (rootA == rootB) {
          if (hasSecrets[a] || hasSecrets[b]) hasSecrets[rootA] = true;
        } else {
          if (sizes[rootA] >= sizes[rootB]) {
            roots[rootB] = rootA;
            sizes[rootA] += sizes[rootB];
            if (hasSecrets[rootB]) hasSecrets[rootA] = true;
          } else {
            roots[rootA] = rootB;
            sizes[rootB] += sizes[rootA];
            if (hasSecrets[rootA]) hasSecrets[rootB] = true;
          }
        }
        ++j;
      }

      for (std::size_t k{i}; k < j; ++k) {
        const int a{meetings[k][0]}, b{meetings[k][1]};
        if (hasSecrets[findRoot(roots, a)]) {
          hasSecrets[a] = true;
          hasSecrets[b] = true;
        }
      }

      for (std::size_t k{i}; k < j; ++k) {
        const int a{meetings[k][0]}, b{meetings[k][1]};
        roots[a] = a;
        roots[b] = b;
        sizes[a] = 1;
        sizes[b] = 1;
      }

      i = j;
    }

    std::vector<int> output{};
    for (int i{0}; i < n; ++i) {
      if (hasSecrets[i]) output.push_back(i);
    }
    return output;
  }

 private:
  static int findRoot(std::vector<int>& roots, int n) {
    return roots[n] == n ? n : roots[n] = findRoot(roots, roots[n]);
  }
};
