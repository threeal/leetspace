#include <vector>

class Solution {
 public:
  int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
    const std::size_t m{grid.size()}, n{grid[0].size()};

    std::vector<std::vector<int>> scores(n, std::vector<int>(k + 1));

    const int score{grid[0][0]};
    if (score == 0) {
      for (int kk{0}; kk <= k; ++kk) scores[0][kk] = 0;
    } else {
      for (int kk{0}; kk < k; ++kk) scores[0][kk] = score;
      scores[0][k] = -1;
    }

    for (std::size_t j{1}; j < n; ++j) {
      const int score{grid[0][j]};
      if (score == 0) {
        for (int kk{0}; kk <= k; ++kk) scores[j][kk] = scores[j - 1][kk];
      } else {
        int kk{0};
        while (kk < k && scores[j - 1][kk + 1] != -1) {
          scores[j][kk] = scores[j - 1][kk + 1] + score;
          ++kk;
        }
        while (kk <= k) {
          scores[j][kk] = -1;
          ++kk;
        }
      }
    }

    for (std::size_t i{1}; i < m; ++i) {
      const int score{grid[i][0]};
      if (score != 0) {
        int kk{0};
        while (kk < k && scores[0][kk + 1] != -1) {
          scores[0][kk] = scores[0][kk + 1] + score;
          ++kk;
        }
        while (kk <= k) {
          scores[0][kk] = -1;
          ++kk;
        }
      }

      for (std::size_t j{1}; j < n; ++j) {
        const int score{grid[i][j]};
        if (score == 0) {
          for (int kk{0}; kk <= k; ++kk) {
            if (scores[j - 1][kk] > scores[j][kk]) {
              scores[j][kk] = scores[j - 1][kk];
            }
          }
        } else {
          int kk{0};
          while (kk < k) {
            if (scores[j][kk + 1] != -1) {
              if (scores[j - 1][kk + 1] > scores[j][kk + 1]) {
                scores[j][kk] = scores[j - 1][kk + 1] + score;
              } else {
                scores[j][kk] = scores[j][kk + 1] + score;
              }
            } else {
              if (scores[j - 1][kk + 1] != -1) {
                scores[j][kk] = scores[j - 1][kk + 1] + score;
              } else {
                break;
              }
            }
            ++kk;
          }
          while (kk <= k) {
            scores[j][kk] = -1;
            ++kk;
          }
        }
      }
    }

    int maxScore{-1};
    for (const int score : scores[n - 1]) {
      if (score != -1 && (maxScore == -1 || score > maxScore)) {
        maxScore = score;
      }
    }

    return maxScore;
  }
};
