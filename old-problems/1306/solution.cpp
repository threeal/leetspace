#include <vector>

class Solution {
 public:
  bool canReach(std::vector<int>& arr, int start) {
    return check(arr, start);
  }

 private:
  bool check(std::vector<int>& arr, int pos) {
    const int val{arr[pos]};
    switch (val) {
      case -1:
        return false;

      case 0:
        return true;

      default:
        arr[pos] = -1;
        if (val <= pos && check(arr, pos - val)) {
          arr[pos] = 0;
          return true;
        }

        if (pos + val < static_cast<int>(arr.size()) &&
            check(arr, pos + val)) {
          arr[pos] = 0;
          return true;
        }

        arr[pos] = -1;
        return false;
    }
  }
};
