#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

long long maximumTotalDamage(int* power, int powerSize) {
  qsort(power, powerSize, sizeof(int), compare);

  long long tot = power[0], tot1 = 0, tot2 = 0, temp;
  for (int i = 1; i < powerSize; ++i) {
    switch (power[i] - power[i - 1]) {
      case 0:
        tot += power[i];
        break;

      case 1:
        temp = tot2 + power[i];
        tot2 = tot2 >= tot1 ? tot2 : tot1;
        tot1 = tot1 >= tot ? tot1 : tot;
        tot = temp;
        break;

      case 2:
        temp = (tot1 >= tot2 ? tot1 : tot2) + power[i];
        if (tot2 > tot1) tot1 = tot2;
        tot1 = tot2 = tot >= tot1 ? tot : tot1;
        tot = temp;
        break;

      default:
        if (tot2 > tot1) tot1 = tot2;
        tot = tot1 = tot2 = tot >= tot1 ? tot : tot1;
        tot += power[i];
    }
  }

  if (tot2 > tot1) tot1 = tot2;
  return tot >= tot1 ? tot : tot1;
}
