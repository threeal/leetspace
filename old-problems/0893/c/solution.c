#include <stdlib.h>
#include <string.h>

char* gWord;
int compareWord(const void* a, const void* b) {
  return gWord[*(int*)a] - gWord[*(int*)b];
}

int compareString(const void* a, const void* b) {
  return strcmp(*(char**)a, *(char**)b);
}

int numSpecialEquivGroups(char** words, int wordsSize) {
  const int wordLen = strlen(words[0]);
  char* str = malloc(wordLen * sizeof(char));

  const int indices0Size = (wordLen + 1) / 2;
  int* indices0 = malloc(indices0Size * sizeof(int));
  for (int i = 0; i < indices0Size; ++i) indices0[i] = i * 2;

  const int indices1Size = wordLen / 2;
  int* indices1 = malloc(indices1Size * sizeof(int));
  for (int i = 0; i < indices1Size; ++i) indices1[i] = i * 2 + 1;

  for (int i = 0; i < wordsSize; ++i) {
    gWord = words[i];
    qsort(indices0, indices0Size, sizeof(int), compareWord);
    qsort(indices1, indices1Size, sizeof(int), compareWord);

    for (int j = 0; j < indices0Size; ++j) {
      str[j * 2] = words[i][indices0[j]];
    }

    for (int j = 0; j < indices1Size; ++j) {
      str[j * 2 + 1] = words[i][indices1[j]];
    }

    memcpy(words[i], str, wordLen * sizeof(char));
  }

  qsort(words, wordsSize, sizeof(char*), compareString);

  int count = 1;
  for (int i = 1; i < wordsSize; ++i) {
    if (strcmp(words[i], words[i - 1]) != 0) ++count;
  }

  free(str);
  free(indices0);
  free(indices1);

  return count;
}
