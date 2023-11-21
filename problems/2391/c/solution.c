// clang-format off
enum GarbageType { Metal = 0, Paper, Glass };
// clang-format on

int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
  (void)travelSize;

  int totalTime[3] = {0};
  int travelTime[3] = {0};

  for (int i = 0; i < garbageSize; ++i) {
    if (i > 0) {
      for (int j = 0; j < 3; ++j) {
        travelTime[j] += travel[i - 1];
      }
    }

    int time[3] = {0};
    char* ci = garbage[i];
    while (*ci != 0) {
      switch (*ci) {
        // clang-format off
        case 'M': ++time[Metal]; break;
        case 'P': ++time[Paper]; break;
        case 'G': ++time[Glass]; break;
          // clang-format on
      }
      ++ci;
    }

    for (int j = 0; j < 3; ++j) {
      if (time[j] > 0) {
        totalTime[j] += travelTime[j] + time[j];
        travelTime[j] = 0;
      }
    }
  }

  return totalTime[Metal] + totalTime[Paper] + totalTime[Glass];
}
