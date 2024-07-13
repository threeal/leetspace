#include <vector>

class Solution {
 public:
  int captureForts(std::vector<int>& forts) {
    for (std::size_t i{forts.size() - 1}; i > 0; --i) {
      if (forts[i] == 0) continue;

      int maxCapture{0};
      int possibleCapture{0};
      bool prevEmpty{forts[i] == -1};

      while (--i > 0) {
        switch (forts[i]) {
          case -1:
            if (!prevEmpty) {
              prevEmpty = true;
              if (possibleCapture > maxCapture) maxCapture = possibleCapture;
            }
            possibleCapture = 0;
            break;

          case 0:
            ++possibleCapture;
            break;

          case 1:
            if (prevEmpty) {
              prevEmpty = false;
              if (possibleCapture > maxCapture) maxCapture = possibleCapture;
            }
            possibleCapture = 0;
        }
      }

      switch (forts[i]) {
        case -1:
          if (!prevEmpty && possibleCapture > maxCapture) {
            maxCapture = possibleCapture;
          }
          break;

        case 1:
          if (prevEmpty && possibleCapture > maxCapture) {
            maxCapture = possibleCapture;
          }
      }

      return maxCapture;
    }
    return 0;
  }
};
