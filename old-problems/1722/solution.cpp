#include <numeric>
#include <vector>

class Solution {
 public:
  int minimumHammingDistance(
      std::vector<int>& source,
      std::vector<int>& target,
      std::vector<std::vector<int>>& allowedSwaps) {
    std::vector<std::size_t> roots(source.size());
    std::iota(roots.begin(), roots.end(), 0);

    for (const auto& swap : allowedSwaps) {
      const std::size_t rootA{getRoots(roots, swap[0])};
      const std::size_t rootB{getRoots(roots, swap[1])};
      if (rootA != rootB) {
        if (rootA < rootB) {
          roots[rootB] = rootA;
        } else {
          roots[rootA] = rootB;
        }
      }
    }

    std::vector<std::size_t> indices(source.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(
        indices.begin(), indices.end(),
        [&roots](std::size_t a, std::size_t b) {
          return getRoots(roots, a) < getRoots(roots, b);
        });

    int hammingDistance{0};
    std::size_t l{0};
    for (std::size_t r{1}; r < source.size(); ++r) {
      if (getRoots(roots, indices[l]) != getRoots(roots, indices[r])) {
        std::unordered_map<int, int> freqs{};
        for (std::size_t i{l}; i < r; ++i) ++freqs[source[indices[i]]];
        for (std::size_t i{l}; i < r; ++i) {
          auto it = freqs.find(target[indices[i]]);
          if (it != freqs.end() && it->second != 0) {
            --it->second;
          } else {
            ++hammingDistance;
          }
        }
        l = r;
      }
    }

    std::unordered_map<int, int> freqs{};
    for (std::size_t i{l}; i < source.size(); ++i) ++freqs[source[indices[i]]];
    for (std::size_t i{l}; i < source.size(); ++i) {
      auto it = freqs.find(target[indices[i]]);
      if (it != freqs.end() && it->second != 0) {
        --it->second;
      } else {
        ++hammingDistance;
      }
    }

    return hammingDistance;
  }

 private:
  static std::size_t getRoots(std::vector<std::size_t>& roots, std::size_t i) {
    return roots[i] != i ? (roots[i] = getRoots(roots, roots[i])) : i;
  }
};
