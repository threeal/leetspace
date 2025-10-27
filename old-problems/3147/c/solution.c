#include <limits.h>

int maximumEnergy(int* energy, int energySize, int k) {
  int maxEnergy = INT_MIN;
  for (int i = energySize - k; i < energySize; ++i) {
    if (energy[i] > maxEnergy) maxEnergy = energy[i];
  }

  for (int i = energySize - k; i > 0; --i) {
    energy[i - 1] += energy[i + k - 1];
    if (energy[i - 1] > maxEnergy) maxEnergy = energy[i - 1];
  }

  return maxEnergy;
}
