#include <string>

class Solution {
 public:
  std::string defangIPaddr(std::string address) {
    address.resize(address.size() + 6);
    for (int l = address.size() - 7, r = address.size() - 1; l >= 0; --l, --r) {
      if (address[l] == '.') {
        address[r] = ']';
        address[--r] = '.';
        address[--r] = '[';
      } else {
        address[r] = address[l];
      }
    }
    return address;
  }
};
