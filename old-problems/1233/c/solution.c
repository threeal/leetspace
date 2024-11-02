#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return strcmp(*(char**)a, *(char**)b);
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
  qsort(folder, folderSize, sizeof(char*), compare);

  char** output = malloc(sizeof(char*) * folderSize);

  int n = -1;
  char* prev = output[++n] = folder[0];
  int prevSize = strlen(prev);

  for (int i = 1; i < folderSize; ++i) {
    int folderSize = strlen(folder[i]);
    if (prevSize < folderSize && folder[i][prevSize] == '/') {
      char temp = folder[i][prevSize];
      folder[i][prevSize] = 0;
      if (strcmp(folder[i], prev) == 0) {
        folder[i][prevSize] = temp;
        continue;
      }
      folder[i][prevSize] = temp;
    }

    prev = output[++n] = folder[i];
    prevSize = folderSize;
  }

  *returnSize = n + 1;
  return output;
}
