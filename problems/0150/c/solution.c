#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
  int stacksIt = 0;
  int* stacks = malloc(sizeof(int) * (tokensSize + 1) / 2);

  for (int i = 0; i < tokensSize; ++i) {
    if (tokens[i][1] == 0) {
      switch (tokens[i][0]) {
        case '+':
          stacks[stacksIt - 2] += stacks[stacksIt - 1];
          --stacksIt;
          break;

        case '-':
          stacks[stacksIt - 2] -= stacks[stacksIt - 1];
          --stacksIt;
          break;

        case '*':
          stacks[stacksIt - 2] *= stacks[stacksIt - 1];
          --stacksIt;
          break;

        case '/':
          stacks[stacksIt - 2] /= stacks[stacksIt - 1];
          --stacksIt;
          break;

        default:
          stacks[stacksIt] = tokens[i][0] - '0';
          ++stacksIt;
          break;
      }
    } else {
      stacks[stacksIt] = atoi(tokens[i]);
      ++stacksIt;
    }
  }

  int res = stacks[stacksIt - 1];
  free(stacks);

  return res;
}
