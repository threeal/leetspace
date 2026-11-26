class Solution {
 public:
  bool canAliceWin(int n) {
    int pick{10};
    bool win{false};
    while (pick <= n) {
      n -= pick--;
      win = !win;
    }
    return win;
  }
};
