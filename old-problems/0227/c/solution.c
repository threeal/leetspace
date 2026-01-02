#include <stdlib.h>

static char priority(char op);
static int calculateOp(int a, char op, int b);

struct operation_t {
  int num;
  int op;
};

int calculate(char* s) {
  int operationsCount = 0;
  for (char* c = s; *c != 0; ++c) {
    switch (*c) {
      case '*':
      case '+':
      case '-':
      case '/':
        ++operationsCount;
    }
  }

  int operationsSize = 0;
  struct operation_t* operations =
      malloc(operationsCount * sizeof(struct operation_t));

  int i = 0;
  while (1) {
    while (s[i] != 0 && s[i] == ' ') ++i;

    int num = 0;
    while (s[i] >= '0') {
      num = num * 10 + (s[i] - '0');
      ++i;
    }

    while (s[i] != 0 && s[i] == ' ') ++i;
    if (s[i] != 0) {
      while (operationsSize != 0 &&
             priority(operations[operationsSize - 1].op) <= priority(s[i])) {
        --operationsSize;
        char op = operations[operationsSize].op;
        int prevNum = operations[operationsSize].num;

        num = calculateOp(prevNum, op, num);
      }

      operations[operationsSize].num = num;
      operations[operationsSize].op = s[i];
      ++operationsSize;
      ++i;
    } else {
      while (operationsSize != 0) {
        --operationsSize;
        char op = operations[operationsSize].op;
        int prevNum = operations[operationsSize].num;

        num = calculateOp(prevNum, op, num);
      }

      free(operations);
      return num;
    }
  }

  free(operations);
  return -1;
}

static char priority(char op) {
  switch (op) {
    case '*':
    case '/':
      return 0;
  }
  return 1;
}

static int calculateOp(int a, char op, int b) {
  switch (op) {
    case '*':
      return a * b;

    case '+':
      return a + b;

    case '-':
      return a - b;

    case '/':
      return a / b;
  }

  return 0;
}
