#include <stdbool.h>

char* pushDominoes(char* dominoes) {
  bool rExist = false;
  int l = 0, r = 0, i = 0;
  while (dominoes[i] != 0) {
    if (dominoes[i] != '.') {
      if (dominoes[i] == 'R') {
        if (rExist) {
          while (++r < i) dominoes[r] = 'R';
        } else {
          rExist = true;
          r = i;
        }
      } else {
        if (rExist) {
          l = i;
          while (++r < --l) {
            dominoes[r] = 'R';
            dominoes[l] = 'L';
          }
          rExist = false;
          l = i + 1;
        } else {
          while (l < i) dominoes[l++] = 'L';
          ++l;
        }
      }
    }
    ++i;
  }

  if (rExist) {
    while (dominoes[++r] != 0) dominoes[r] = 'R';
  }

  return dominoes;
}
