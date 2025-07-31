#include <stdlib.h>
#include <string.h>

char** stringSequence(char* target, int* returnSize) {
  int targetSize = 0, screensSize = 0;
  for (char* c = target; *c != 0; ++c) {
    screensSize += *c + 1 - 'a';
    ++targetSize;
  }

  char** screens = malloc(screensSize * sizeof(char*));
  screensSize = 0;

  char* screen = malloc((targetSize + 1) * sizeof(char));
  int screenSize = 0;

  while (screenSize < targetSize) {
    screen[screenSize] = 'a';
    screen[++screenSize] = 0;

    screens[screensSize] = malloc((screenSize + 1) * sizeof(char));
    memcpy(screens[screensSize++], screen, (screenSize + 1) * sizeof(char));

    const int i = screenSize - 1;
    while (screen[i] != target[i]) {
      ++screen[i];

      screens[screensSize] = malloc((screenSize + 1) * sizeof(char));
      memcpy(screens[screensSize++], screen, (screenSize + 1) * sizeof(char));
    }
  }

  free(screen);

  *returnSize = screensSize;
  return screens;
}
