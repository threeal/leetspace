#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t compareEmail(const char* a, const char* b);

int numUniqueEmails(char** emails, int emailsSize) {
  int uniques = 0;

  uint8_t* checked = malloc(emailsSize * sizeof(uint8_t));
  memset(checked, 0, emailsSize * sizeof(uint8_t));

  for (int i = emailsSize - 1; i >= 0; --i) {
    if (checked[i]) continue;

    ++uniques;
    for (int j = i - 1; j >= 0; --j) {
      if (checked[j]) continue;
      if (compareEmail(emails[i], emails[j]))
        checked[j] = 1;
    }
  }

  free(checked);
  return uniques;
}

uint8_t compareEmail(const char* a, const char* b) {
  while (*a != '@' && *b != '@' && *a == *b) {
    while (*(++a) == '.') continue;
    if (*a == '+') {
      while (*a != '@') ++a;
    }

    while (*(++b) == '.') continue;
    if (*b == '+') {
      while (*b != '@') ++b;
    }
  }

  return (*a == '@' && *b == '@')
      ? strcmp(a, b) == 0
      : 0;
}
