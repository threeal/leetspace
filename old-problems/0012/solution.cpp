#include <string>

class Solution {
 public:
  std::string intToRoman(int num) {
    std::string s = "";
    while (num >= 1000) {
      s += "M";
      num -= 1000;
    }

    if (num >= 900) {
      s += "CM";
      num -= 900;
    } else if (num >= 600) {
      s += "D";
      while (num >= 600) {
        s += "C";
        num -= 100;
      }
      num -= 500;
    } else if (num >= 500) {
      s += "D";
      num -= 500;
    } else if (num >= 400) {
      s += "CD";
      num -= 400;
    } else {
      while (num >= 100) {
        s += "C";
        num -= 100;
      }
    }

    if (num >= 90) {
      s += "XC";
      num -= 90;
    } else if (num >= 60) {
      s += "L";
      while (num >= 60) {
        s += "X";
        num -= 10;
      }
      num -= 50;
    } else if (num >= 50) {
      s += "L";
      num -= 50;
    } else if (num >= 40) {
      s += "XL";
      num -= 40;
    } else {
      while (num >= 10) {
        s += "X";
        num -= 10;
      }
    }

    if (num >= 9) {
      s += "IX";
      num -= 9;
    } else if (num >= 6) {
      s += "V";
      while (num >= 6) {
        s += "I";
        num -= 1;
      }
      num -= 5;
    } else if (num >= 5) {
      s += "V";
      num -= 5;
    } else if (num >= 4) {
      s += "IV";
      num -= 4;
    } else {
      while (num >= 1) {
        s += "I";
        num -= 1;
      }
    }

    return s;
  }
};
