#include <string.h>

char* reverseStr(char* s, int k) {
  const int n = strlen(s);
  for (int i = 0; i < n; i += k + k) {
    int left = i;
    int right = i + k - 1;
    if (right >= n) right = n - 1;
    while (left < right) {
      const char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      ++left;
      --right;
    }
  }
  return s;
}
