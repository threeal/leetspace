#include <limits.h>

int earliestFinishTime(
    int* landStartTime, int landStartTimeSize,
    int* landDuration, int landDurationSize,
    int* waterStartTime, int waterStartTimeSize,
    int* waterDuration, int waterDurationSize) {
  (void)landDurationSize;
  (void)waterDurationSize;
  int minTime = INT_MAX;
  for (int i = 0; i < landStartTimeSize; ++i) {
    for (int j = 0; j < waterStartTimeSize; ++j) {
      int startTime = landStartTime[i] + landDuration[i];
      if (waterStartTime[j] > startTime) startTime = waterStartTime[j];
      const int waterEndTime = startTime + waterDuration[j];

      startTime = waterStartTime[j] + waterDuration[j];
      if (landStartTime[i] > startTime) startTime = landStartTime[i];
      const int landEndTime = startTime + landDuration[i];

      const int time = waterEndTime < landEndTime ? waterEndTime : landEndTime;
      if (time < minTime) minTime = time;
    }
  }
  return minTime;
}
