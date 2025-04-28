#include <string>

class Solution {
 public:
  std::string convertDateToBinary(std::string date) {
    std::string output(25, '0');
    std::size_t i{0}, j{0};

    int num{0};
    while (date[i] != '-') {
      num = num * 10 + date[i] - '0';
      ++i;
    }

    int bit{1 << 12};
    while ((num & bit) == 0) bit >>= 1;
    while (bit != 0) {
      if ((num & bit) != 0) ++output[j];
      bit >>= 1;
      ++j;
    }

    ++i;
    output[j++] = '-';

    num = 0;
    while (date[i] != '-') {
      num = num * 10 + date[i] - '0';
      ++i;
    }

    bit = 1 << 5;
    while ((num & bit) == 0) bit >>= 1;
    while (bit != 0) {
      if ((num & bit) != 0) ++output[j];
      bit >>= 1;
      ++j;
    }

    ++i;
    output[j++] = '-';

    num = 0;
    while (date[i] != 0) {
      num = num * 10 + date[i] - '0';
      ++i;
    }

    bit = 1 << 6;
    while ((num & bit) == 0) bit >>= 1;
    while (bit != 0) {
      if ((num & bit) != 0) ++output[j];
      bit >>= 1;
      ++j;
    }

    output.resize(j);
    return output;
  }
};
