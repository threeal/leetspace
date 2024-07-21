#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
  int fives = 0, tens = 0;
  for (int i = 0; i < billsSize; ++i) {
    switch (bills[i]) {
      case 5:
        ++fives;
        break;

      case 10:
        if (fives <= 0) return false;
        --fives;
        ++tens;
        break;

      case 20:
        if (tens <= 0) {
          if (fives <= 2) return false;
          fives -= 3;
        } else {
          if (fives <= 0) return false;
          --fives;
          --tens;
        }
    }
  }

  return true;
}
