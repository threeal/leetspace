#include <stdbool.h>

bool isInterleave(char* s1, char* s2, char* s3) {
  return *s1 == *s3 && *s2 == *s3;
}
