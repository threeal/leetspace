class Solution {
 public:
  bool winnerOfGame(string colors) {
    size_t a = 0;
    size_t b = 0;

    size_t start = 0;
    const size_t n = colors.size();
    for (size_t i = 1; i < n; ++i) {
      if (colors[i] != colors[start]) {
        if (i - start > 2) {
          if (colors[start] == 'A') {
            a += i - start - 2;
          } else {
            b += i - start - 2;
          }
        }
        start = i;
      }
    }

    return a > b;
  }
};
