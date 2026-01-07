#include <stdbool.h>

bool validateStackSequences(
    int* pushed, int pushedSize, int* popped, int poppedSize) {
  return pushed[pushedSize - 1] == popped[poppedSize - 1];
}
