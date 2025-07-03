#include <stdbool.h>

bool isBalanced(char* num) {
  int even = 0, odd = 0;
  for (int i = 0; num[i] != 0; ++i) {
    even += num[i] - '0';
    if (num[++i] == 0) break;
    odd += num[i] - '0';
  }
  return even == odd;
}
