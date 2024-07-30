#include <stdlib.h>
#include <string.h>

int numTeams(int* rating, int ratingSize) {
  int* lessers = malloc(ratingSize * sizeof(int));
  memset(lessers, 0, ratingSize * sizeof(int));

  int* greaters = malloc(ratingSize * sizeof(int));
  memset(greaters, 0, ratingSize * sizeof(int));

  int count = 0;
  for (int i = ratingSize - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (rating[i] > rating[j]) {
        count += greaters[i];
        ++greaters[j];
      } else {
        count += lessers[i];
        ++lessers[j];
      }
    }
  }

  return count;
}
