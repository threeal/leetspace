#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
  const int num1Len = strlen(num1);
  const int num2Len = strlen(num2);

  int l = 0;
  int r = num1Len - 1;
  while (l < r) {
    int temp = num1[l] - '0';
    num1[l] = num1[r] - '0';
    num1[r] = temp;
    ++l, --r;
  }
  if (l == r) num1[l] -= '0';

  l = 0;
  r = num2Len - 1;
  while (l < r) {
    int temp = num2[l] - '0';
    num2[l] = num2[r] - '0';
    num2[r] = temp;
    ++l, --r;
  }
  if (l == r) num2[l] -= '0';

  int outputSize = num1Len + num2Len;
  char* output = malloc((outputSize + 1) * sizeof(char));
  memset(output, 0, (outputSize + 1) * sizeof(char));

  char carry = 0;
  for (int i = 0; i < num1Len; ++i) {
    for (int j = 0; j < num2Len; ++j) {
      carry += output[i + j] + num1[i] * num2[j];
      output[i + j] = carry % 10;
      carry /= 10;
    }
    if (carry > 0) {
      output[i + num2Len] += carry;
      carry = 0;
    }
  }

  while (outputSize != 0 && output[outputSize - 1] == 0) --outputSize;
  if (outputSize == 0) return "0";

  l = 0;
  r = outputSize - 1;
  while (l < r) {
    int temp = output[l] + '0';
    output[l] = output[r] + '0';
    output[r] = temp;
    ++l, --r;
  }
  if (l == r) output[l] += '0';

  return output;
}
