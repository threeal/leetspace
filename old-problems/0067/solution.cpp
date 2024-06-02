#include <string>
#include <utility>

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    if (a.size() < b.size()) std::swap(a, b);

    bool remainder{false};
    for (int i = a.size() - 1, j = b.size() - 1; j >= 0; --i, --j) {
      switch (a[i]) {
        case '0':
          switch (b[j]) {
            case '0':
              if (remainder) {
                remainder = false;
                a[i] = '1';
              }
              break;

            case '1':
              if (!remainder) {
                a[i] = '1';
              }
              break;
          }
          break;

        case '1':
          switch (b[j]) {
            case '0':
              if (remainder) {
                a[i] = '0';
              }
              break;

            case '1':
              if (!remainder) {
                remainder = true;
                a[i] = '0';
              }
              break;
          }
          break;
      }
    }

    for (int i = a.size() - b.size() - 1; i >= 0 && remainder; --i) {
      switch (a[i]) {
        case '0':
          a[i] = '1';
          remainder = false;
          break;

        case '1':
          a[i] = '0';
          break;
      }
    }

    if (remainder) {
      a = "1" + a;
    }

    return a;
  }
};
