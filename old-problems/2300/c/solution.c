#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* successfulPairs(
    int* spells, int spellsSize, int* potions, int potionsSize,
    long long success, int* returnSize) {
  qsort(potions, potionsSize, sizeof(int), compare);

  for (int i = 0; i < spellsSize; ++i) {
    const long long spell = spells[i];

    int low = 0, high = potionsSize - 1;
    while (low < high) {
      const int mid = low + (high - low) / 2;
      if (spell * potions[mid] < success) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    spells[i] = spell * potions[low] >= success
        ? potionsSize - low
        : 0;
  }

  *returnSize = spellsSize;
  return spells;
}
