#include <stdlib.h>
#include <string.h>

int calPoints(char** operations, int operationsSize) {
  int totalScore = 0;

  int* scores = malloc(operationsSize * sizeof(int));
  int scoresSize = 0;

  for (int i = 0; i < operationsSize; ++i) {
    switch (operations[i][0]) {
      case '+':
        scores[scoresSize] = scores[scoresSize - 1] + scores[scoresSize - 2];
        totalScore += scores[scoresSize];
        ++scoresSize;
        break;

      case 'D':
        scores[scoresSize] = scores[scoresSize - 1] * 2;
        totalScore += scores[scoresSize];
        ++scoresSize;
        break;

      case 'C':
        totalScore -= scores[--scoresSize];
        break;

      default:
        scores[scoresSize] = atoi(operations[i]);
        totalScore += scores[scoresSize];
        ++scoresSize;
    };
  }

  return totalScore;
}
