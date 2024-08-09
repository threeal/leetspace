#include <stdio.h>
#include <stdlib.h>

char** fizzBuzz(int n, int* returnSize) {
  char** output = malloc(n * sizeof(char*));
  char** it = output;

  for (int i = 1; i <= n; ++i) {
    if (i % 3 == 0) {
      if (i % 5 == 0) {
        *it = "FizzBuzz";
      } else {
        *it = "Fizz";
      }
    } else if (i % 5 == 0) {
      *it = "Buzz";
    } else {
      *it = malloc(5 * sizeof(char));
      sprintf(*it, "%d", i);
    }
    ++it;
  }

  *returnSize = n;
  return output;
}
