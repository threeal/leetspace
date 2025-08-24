#include <limits.h>
#include <string.h>

int maxDifference(char* s, int k) {
  const int n = strlen(s);
  int maxDiff = INT_MIN;
  for (char a = '0'; a <= '4'; ++a) {
    for (char b = '0'; b <= '4'; ++b) {
      if (a == b) continue;

      int l = -1;
      int minPrev[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};

      int prevA = 0, prevB = 0;
      int countA = 0, countB = 0;
      int prevStatus = 0, status = 2;

      for (int r = 0; r < n; ++r) {
        if (s[r] == a) {
          ++countA;
          status ^= 2;
        } else if (s[r] == b) {
          ++countB;
          status ^= 1;
        }

        while (r - l >= k && countB - prevB >= 2) {
          if (prevA - prevB < minPrev[prevStatus]) {
            minPrev[prevStatus] = prevA - prevB;
          }

          ++l;
          if (s[l] == a) {
            ++prevA;
            prevStatus ^= 2;
          } else if (s[l] == b) {
            ++prevB;
            prevStatus ^= 1;
          }
        }

        if (minPrev[status] != INT_MAX) {
          if (countA - countB - minPrev[status] > maxDiff) {
            maxDiff = countA - countB - minPrev[status];
          }
        }
      }
    }
  }
  return maxDiff;
}
