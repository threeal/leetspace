#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
  int num1Len = strlen(num1);
  int num2Len = strlen(num2);

  if (num1Len < num2Len) {
    char* temp = num1;
    const int tempLen = num1Len;

    num1 = num2;
    num1Len = num2Len;

    num2 = temp;
    num2Len = tempLen;
  }

  char carry = 0;
  int i1 = num1Len - 1;
  for (int i2 = num2Len - 1; i2 >= 0; --i1, --i2) {
    num1[i1] += carry + num2[i2] - '0';
    if (num1[i1] > '9') {
      num1[i1] -= 10;
      carry = 1;
    } else {
      carry = 0;
    }
  }

  while (carry >= 0 && i1 >= 0) {
    num1[i1] += carry;
    if (num1[i1] > '9') {
      num1[i1] -= 10;
      carry = 1;
    } else {
      carry = 0;
    }
    --i1;
  }

  if (carry == 0) return num1;

  char* temp = malloc((num1Len + 2) * sizeof(char));
  temp[0] = '1';
  memcpy(temp + 1, num1, (num1Len + 1) * sizeof(char));

  return temp;
}
