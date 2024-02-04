#include <stdint.h>
#include <wchar.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
  int32_t futures[71] = {-1};

  for (int32_t i = temperaturesSize - 1; i >= 0; --i) {
    const int8_t temperature = temperatures[i] - 30;
    temperatures[i] = futures[temperature] > 0 ? futures[temperature] - i : 0;
    wmemset(futures, i, temperature);
  }

  *returnSize = temperaturesSize;
  return temperatures;
}
