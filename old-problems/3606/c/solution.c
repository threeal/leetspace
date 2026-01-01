#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool isValid(char* code, char* businessLine, bool isActive);

char** gCode;
char** gBusinessLine;
int compare(const void* a, const void* b) {
  const int aa = *(int*)a;
  const int bb = *(int*)b;
  return gBusinessLine[aa][0] != gBusinessLine[bb][0]
      ? gBusinessLine[aa][0] - gBusinessLine[bb][0]
      : strcmp(gCode[aa], gCode[bb]);
}

char** validateCoupons(
    char** code, int codeSize, char** businessLine, int businessLineSize,
    bool* isActive, int isActiveSize, int* returnSize) {
  (void)businessLineSize;
  (void)isActiveSize;

  int n = 0;
  int* indices = malloc(codeSize * sizeof(int));
  for (int i = 0; i < codeSize; ++i) {
    if (isValid(code[i], businessLine[i], isActive[i])) {
      indices[n++] = i;
    }
  }

  gCode = code;
  gBusinessLine = businessLine;
  qsort(indices, n, sizeof(int), compare);

  for (int i = 0; i < n; ++i) {
    businessLine[i] = code[indices[i]];
  }

  free(indices);

  *returnSize = n;
  return businessLine;
}

static bool isValid(char* code, char* businessLine, bool isActive) {
  if (code[0] == 0 || businessLine[0] == 0 || !isActive) return false;

  switch (businessLine[0]) {
    case 'e':
      if (strcmp(businessLine, "electronics") != 0) return false;
      break;

    case 'g':
      if (strcmp(businessLine, "grocery") != 0) return false;
      break;

    case 'p':
      if (strcmp(businessLine, "pharmacy") != 0) return false;
      break;

    case 'r':
      if (strcmp(businessLine, "restaurant") != 0) return false;
      break;

    default:
      return false;
  }

  for (char* c = code; *c != 0; ++c) {
    if (*c == '_') continue;
    if (*c >= 'a' && *c <= 'z') continue;
    if (*c >= 'A' && *c <= 'Z') continue;
    if (*c >= '0' && *c <= '9') continue;
    return false;
  }

  return true;
}
