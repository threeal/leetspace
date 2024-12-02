class Solution {
 public:
  int rotatedDigits(int n) {
    int counts{0};
    bool rotateable{false};

    switch ((n / 100) % 10) {
      case 9:
        rotateable = true;
        counts += 33;
        break;

      case 8:
      case 7:
        counts += 29;
        break;

      case 6:
        rotateable = true;
        counts += 22;
        break;

      case 5:
        rotateable = true;
        counts += 15;
        break;

      case 4:
      case 3:
        counts += 15;
        break;

      case 2:
        rotateable = true;
        counts += 8;
        break;

      case 1:
        counts += 33;
    }

    switch ((n / 10) % 10) {
      case 9:
        rotateable = true;
        counts += 33;
        break;

      case 8:
      case 7:
        counts += 29;
        break;

      case 6:
        rotateable = true;
        counts += 22;
        break;

      case 5:
        rotateable = true;
        counts += 15;
        break;

      case 4:
      case 3:
        counts += 15;
        break;

      case 2:
        rotateable = true;
        counts += 8;
        break;

      case 1:
        counts += 4;
    }

    switch (n % 10) {
      case 9:
        counts += rotateable ? 7 : 4;
        break;

      case 8:
        counts += rotateable ? 6 : 3;
        break;

      case 7:
      case 6:
        counts += 5;
        break;

      case 5:
        counts += rotateable ? 4 : 2;
        break;

      case 4:
      case 3:
      case 2:
        counts += rotateable ? 3 : 1;
        break;

      case 1:
        if (rotateable) counts += 2;
        break;

      case 0:
        if (rotateable) ++counts;
    }

    return counts;
  }
};
