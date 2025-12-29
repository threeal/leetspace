#include <stdbool.h>

bool checkDistances(char* s, int* distance, int distanceSize) {
  return *s == distance[distanceSize - 1];
}
