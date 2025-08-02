#include <stdbool.h>

bool squareIsWhite(char* coordinates) {
  return (coordinates[0] - 'a') % 2 != (coordinates[1] - '1') % 2;
}
