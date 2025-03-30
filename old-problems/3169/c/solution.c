#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return aa[0] == bb[0] ? aa[1] - bb[1] : aa[0] - bb[0];
}

int countDays(
    int days, int** meetings, int meetingsSize, int* meetingsColSize) {
  (void)meetingsColSize;

  qsort(meetings, meetingsSize, sizeof(int*), compare);

  int totalDay = 0, day = 1;
  for (int i = 0; i < meetingsSize; ++i) {
    if (meetings[i][0] > day) totalDay += meetings[i][0] - day;
    if (meetings[i][1] >= day) day = meetings[i][1] + 1;
  }

  if (days >= day) totalDay += days - day + 1;

  return totalDay;
}
