#include <stdlib.h>
#include <string.h>

char* toGoatLatin(char* sentence) {
  const int sentenceLen = strlen(sentence);

  int words = 1;
  for (int i = 0; i < sentenceLen; ++i) {
    if (sentence[i] == ' ') ++words;
  }

  const int outputSize = sentenceLen + words * 2 + words * (words + 1) / 2;
  char* output = malloc((outputSize + 1) * sizeof(char));

  int l = 0, i = 0, as = 2;
  for (int r = 1; r <= sentenceLen; ++r) {
    if (r == sentenceLen || sentence[r] == ' ') {
      switch (sentence[l]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
          for (int j = l; j < r; ++j, ++i) {
            output[i] = sentence[j];
          }
          break;

        default:
          for (int j = l + 1; j < r; ++j, ++i) {
            output[i] = sentence[j];
          }
          output[i++] = sentence[l];
      }

      output[i++] = 'm';
      for (int a = 0; a < as; ++a) {
        output[i++] = 'a';
      }
      output[i++] = ' ';

      l = r + 1;
      ++as;
    }
  }

  output[outputSize] = 0;
  return output;
}
