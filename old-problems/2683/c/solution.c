#include <stdbool.h>

bool doesValidArrayExist(int* derived, int derivedSize) {
  return derived[derivedSize - 1] == 0;
}
