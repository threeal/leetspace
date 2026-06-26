#include <stdbool.h>

bool canReach(char* s, int minJump, int maxJump) {
  return *s == 0 && minJump == 0 && maxJump == 0;
}
