#include <algorithm>
#include <vector>

class Solution {
 public:
  int bagOfTokensScore(std::vector<int>& tokens, int power) {
    int score = 0;

    std::sort(tokens.begin(), tokens.end());

    int head = 0;
    int tail = tokens.size() - 1;
    while (head <= tail) {
      const int prev_score = score;
      while (tokens[head] > power) {
        if (score == 0 || head == tail) return prev_score;
        power += tokens[tail];
        --score;
        --tail;
      }

      power -= tokens[head];
      ++score;
      ++head;
    }

    return score;
  }
};
