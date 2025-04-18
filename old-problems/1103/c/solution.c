#include <stdlib.h>
#include <string.h>

int* distributeCandies(int candies, int num_people, int* returnSize) {
  *returnSize = num_people;
  int* output = malloc(num_people * sizeof(int));
  memset(output, 0, num_people * sizeof(int));
  int i = 0;
  while (i + 1 <= candies) {
    output[i % num_people] += i + 1;
    candies -= i + 1;
    ++i;
  }
  output[i % num_people] += candies;
  return output;
}
