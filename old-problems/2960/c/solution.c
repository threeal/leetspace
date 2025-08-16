int countTestedDevices(int* batteryPercentages, int batteryPercentagesSize) {
  int count = 0;
  for (int i = 0; i < batteryPercentagesSize; ++i) {
    if (batteryPercentages[i] > count) ++count;
  }
  return count;
}
