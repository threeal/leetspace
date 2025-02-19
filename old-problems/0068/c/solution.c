#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
  int* wordLens = malloc(wordsSize * sizeof(int));
  for (int i = 0; i < wordsSize; ++i) {
    wordLens[i] = strlen(words[i]);
  }

  char* line = malloc((maxWidth + 1) * sizeof(char));
  for (int i = 0; i < maxWidth; ++i) line[i] = ' ';
  line[maxWidth] = '\0';

  int outputSize = 0;
  char** output = malloc(wordsSize * sizeof(char*));

  int l = 0, width = wordLens[0];
  for (int r = 1; r < wordsSize; ++r) {
    if (width + wordLens[r] + 1 <= maxWidth) {
      width += wordLens[r] + 1;
      continue;
    }

    if (r - l > 1) {
      memcpy(line, words[l], wordLens[l] * sizeof(char));

      int pos = wordLens[l];
      int spaceWidth = 1 + (maxWidth - width) / (r - l - 1);
      int extraSpaces = (maxWidth - width) % (r - l - 1);

      for (++l; l < r; ++l) {
        if (extraSpaces > 0) {
          memset(line + pos, ' ', (spaceWidth + 1) * sizeof(char));
          pos += spaceWidth + 1;
          --extraSpaces;
        } else {
          memset(line + pos, ' ', spaceWidth * sizeof(char));
          pos += spaceWidth;
        }
        memcpy(line + pos, words[l], wordLens[l] * sizeof(char));
        pos += wordLens[l];
      }
    } else {
      memcpy(line, words[l], wordLens[l] * sizeof(char));
      memset(line + wordLens[l], ' ', (maxWidth - wordLens[l]) * sizeof(char));
      ++l;
    }

    output[outputSize] = malloc((maxWidth + 1) * sizeof(char));
    memcpy(output[outputSize], line, (maxWidth + 1) * sizeof(char));
    ++outputSize;

    width = wordLens[r];
  }

  memcpy(line, words[l], wordLens[l] * sizeof(char));
  int pos = wordLens[l];

  for (++l; l < wordsSize; ++l) {
    line[pos++] = ' ';
    memcpy(line + pos, words[l], wordLens[l] * sizeof(char));
    pos += wordLens[l];
  }

  memset(line + pos, ' ', (maxWidth - pos) * sizeof(char));

  output[outputSize] = line;
  ++outputSize;

  free(wordLens);

  *returnSize = outputSize;
  return output;
}
