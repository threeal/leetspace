#include <stdbool.h>

bool judgeCircle(char* moves) {
  int horizontal = 0, vertical = 0;
  while (*moves != 0) {
    switch (*moves) {
      case 'L':
        --horizontal;
        break;

      case 'R':
        ++horizontal;
        break;

      case 'U':
        --vertical;
        break;

      case 'D':
        ++vertical;
    }
    ++moves;
  }
  return horizontal == 0 && vertical == 0;
}
