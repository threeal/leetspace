#include <stdbool.h>

bool isNumber(char* s) {
  if (*s == '+' || *s == '-') ++s;
  if (*s != 0) {
    if (*s == '.') {
      ++s;
      if (*s >= '0' && *s <= '9') {
        ++s;
        while (*s != 0 && *s >= '0' && *s <= '9') ++s;
        if (*s == 0) return true;

        if (*s == 'e' || *s == 'E') {
          ++s;
          if (*s == '+' || *s == '-') ++s;
          if (*s != 0 && *s >= '0' && *s <= '9') {
            ++s;
            while (*s != 0 && *s >= '0' && *s <= '9') ++s;
            if (*s == 0) return true;
          }
        }
      }
    } else if (*s >= '0' && *s <= '9') {
      ++s;
      while (*s != 0 && *s >= '0' && *s <= '9') ++s;
      if (*s == 0) return true;

      if (*s == '.') {
        ++s;
        if (*s == 0) return true;

        if (*s >= '0' && *s <= '9') {
          ++s;
          while (*s != 0 && *s >= '0' && *s <= '9') ++s;
          if (*s == 0) return true;

          if (*s == 'e' || *s == 'E') {
            ++s;
            if (*s == '+' || *s == '-') ++s;
            if (*s != 0 && *s >= '0' && *s <= '9') {
              ++s;
              while (*s != 0 && *s >= '0' && *s <= '9') ++s;
              if (*s == 0) return true;
            }
          }
        } else if (*s == 'e' || *s == 'E') {
          ++s;
          if (*s == '+' || *s == '-') ++s;
          if (*s != 0 && *s >= '0' && *s <= '9') {
            ++s;
            while (*s != 0 && *s >= '0' && *s <= '9') ++s;
            if (*s == 0) return true;
          }
        }
      } else if (*s == 'e' || *s == 'E') {
        ++s;
        if (*s == '+' || *s == '-') ++s;
        if (*s != 0 && *s >= '0' && *s <= '9') {
          ++s;
          while (*s != 0 && *s >= '0' && *s <= '9') ++s;
          if (*s == 0) return true;
        }
      }
    }
  }
  return false;
}
