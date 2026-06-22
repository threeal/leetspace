#include <stdlib.h>
#include <string.h>

char* mapWordWeights(
    char** words, int wordsSize, int* weights, int weightsSize) {
  (void)weightsSize;
  char* output = malloc((wordsSize + 1) * sizeof(char));
  memset(output, 'z', wordsSize * sizeof(char));
  output[wordsSize] = 0;
  for (int i = 0; i < wordsSize; ++i) {
    int sum = 0;
    for (char* c = words[i]; *c != 0; ++c) sum += weights[*c - 'a'];
    output[i] -= sum % 26;
  }
  return output;
}
