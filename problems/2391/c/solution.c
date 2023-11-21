// The solution can simply be done by iterating over the garbage to sum the required times.
// To calculate the travel time, one should only add it to the total time if there's some garbage in a house.

// clang-format off
enum GarbageType { Metal = 0, Paper, Glass };
// clang-format on

int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
  (void)travelSize;

  int totalTime[3] = {0};
  int travelTime[3] = {0};

  // Iterating over the garbage in every house.
  for (int i = 0; i < garbageSize; ++i) {
    // Remember the travel time, don't add it to the total time yet.
    if (i > 0) {
      for (int j = 0; j < 3; ++j) {
        travelTime[j] += travel[i - 1];
      }
    }

    // Calculate garbage in the house.
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

    // Add garbage count and travel time if there's some garbage in the house.
    for (int j = 0; j < 3; ++j) {
      if (time[j] > 0) {
        totalTime[j] += travelTime[j] + time[j];
        travelTime[j] = 0;
      }
    }
  }

  // Return the total time required by all types of garbage.
  return totalTime[Metal] + totalTime[Paper] + totalTime[Glass];
}
