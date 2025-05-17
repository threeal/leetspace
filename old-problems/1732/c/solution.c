int largestAltitude(int* gain, int gainSize) {
  int maxAltitude = 0, altitude = 0;
  for (int i = 0; i < gainSize; ++i) {
    altitude += gain[i];
    if (altitude > maxAltitude) maxAltitude = altitude;
  }
  return maxAltitude;
}
