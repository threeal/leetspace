#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void check(
    int i, int numCourses, bool* isPrerequisite, bool* isChecked);

bool* checkIfPrerequisite(
    int numCourses,
    int** prerequisites, int prerequisitesSize, int* prerequisitesColSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  (void)prerequisitesColSize;
  (void)queriesColSize;

  bool* isPrerequisite = malloc(numCourses * numCourses * sizeof(bool));
  memset(isPrerequisite, 0, numCourses * numCourses * sizeof(bool));

  for (int i = 0; i < prerequisitesSize; ++i) {
    isPrerequisite[prerequisites[i][0] * numCourses + prerequisites[i][1]] = true;
  }

  bool* isChecked = malloc(numCourses * sizeof(bool));
  memset(isChecked, 0, numCourses * sizeof(bool));

  bool* output = malloc(queriesSize * sizeof(bool));
  *returnSize = queriesSize;

  for (int i = 0; i < queriesSize; ++i) {
    if (!isChecked[queries[i][0]]) {
      check(queries[i][0], numCourses, isPrerequisite, isChecked);
    }
    output[i] = isPrerequisite[queries[i][0] * numCourses + queries[i][1]];
  }

  return output;
}

static void check(
    int i, int numCourses, bool* isPrerequisite, bool* isChecked) {
  isChecked[i] = true;
  for (int j = 0; j < numCourses; ++j) {
    if (!isPrerequisite[i * numCourses + j]) continue;
    if (!isChecked[j]) check(j, numCourses, isPrerequisite, isChecked);
    for (int k = 0; k < numCourses; ++k) {
      if (!isPrerequisite[j * numCourses + k]) continue;
      isPrerequisite[i * numCourses + k] = true;
    }
  }
}
