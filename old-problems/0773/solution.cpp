#include <queue>
#include <unordered_set>
#include <vector>

static constexpr int target{0123450};

class Solution {
 public:
  int slidingPuzzle(std::vector<std::vector<int>>& board) {
    const int pattern{
        (board[0][0] << 15) | (board[0][1] << 12) | (board[0][2] << 9) |
        (board[1][0] << 6) | (board[1][1] << 3) | board[1][2]};

    if (pattern == target) return 0;

    std::queue<int> queue{};
    queue.push(pattern);

    std::unordered_set<int> visited{};
    visited.insert(pattern);

    for (int step{1}; !queue.empty(); ++step) {
      for (std::size_t n{queue.size()}; n > 0; --n) {
        const int current{queue.front()};
        queue.pop();

        if ((current & 0000'007) == 0) {
          int next = (current & 0777'700) | ((current & 0000'070) >> 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0770'770) | ((current & 0007'000) >> 9);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }
        } else if ((current & 0000'070) == 0) {
          int next = (current & 0777'007) | ((current & 0000'700) >> 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0707'707) | ((current & 0070'000) >> 9);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0777'700) | ((current & 0000'007) << 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }
        } else if ((current & 0000'700) == 0) {
          int next = (current & 0077'077) | ((current & 0700'000) >> 9);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0777'007) | ((current & 0000'070) << 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }
        } else if ((current & 0007'000) == 0) {
          int next = (current & 0700'777) | ((current & 0070'000) >> 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0770'770) | ((current & 0000'007) << 9);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }
        } else if ((current & 0070'000) == 0) {
          int next = (current & 0007'777) | ((current & 0700'000) >> 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0707'707) | ((current & 0000'070) << 9);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0700'777) | ((current & 0007'000) << 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }
        } else if ((current & 0700'000) == 0) {
          int next = (current & 0077'077) | ((current & 0000'700) << 9);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }

          next = (current & 0007'777) | ((current & 0070'000) << 3);
          if (next == target) return step;
          if (!visited.contains(next)) {
            visited.insert(next);
            queue.push(next);
          }
        }
      }
    }

    return -1;
  }
};
