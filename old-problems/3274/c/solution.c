#include <stdbool.h>

bool checkTwoChessboards(char* coordinate1, char* coordinate2) {
  return (coordinate1[0] + coordinate1[1]) % 2 ==
      (coordinate2[0] + coordinate2[1]) % 2;
}
