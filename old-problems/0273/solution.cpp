#include <sstream>
#include <string>

static void first(std::stringstream& ss, int num) {
  switch (num) {
      // clang-format off
    case 1: ss << "One"; break;
    case 2: ss << "Two"; break;
    case 3: ss << "Three"; break;
    case 4: ss << "Four"; break;
    case 5: ss << "Five"; break;
    case 6: ss << "Six"; break;
    case 7: ss << "Seven"; break;
    case 8: ss << "Eight"; break;
    case 9: ss << "Nine"; break;
      // clang-format on
  }
}

static void tenth(std::stringstream& ss, int num) {
  if (num >= 20) {
    // clang-format off
    switch (num / 10) {
      case 2: ss << "Twenty"; break;
      case 3: ss << "Thirty"; break;
      case 4: ss << "Forty"; break;
      case 5: ss << "Fifty"; break;
      case 6: ss << "Sixty"; break;
      case 7: ss << "Seventy"; break;
      case 8: ss << "Eighty"; break;
      case 9: ss << "Ninety"; break;
    }
    // clang-format on

    num %= 10;
    if (num > 0) {
      ss << " ";
      first(ss, num);
    }
  } else {
    // clang-format off
    switch (num) {
      case 10: ss << "Ten"; break;
      case 11: ss << "Eleven"; break;
      case 12: ss << "Twelve"; break;
      case 13: ss << "Thirteen"; break;
      case 14: ss << "Fourteen"; break;
      case 15: ss << "Fifteen"; break;
      case 16: ss << "Sixteen"; break;
      case 17: ss << "Seventeen"; break;
      case 18: ss << "Eighteen"; break;
      case 19: ss << "Nineteen"; break;
      default: first(ss, num);
    }
    // clang-format on
  }
}

static void hundredth(std::stringstream& ss, int num) {
  if (num >= 100) {
    first(ss, num / 100);
    ss << " Hundred";
    num %= 100;
    if (num > 0) {
      ss << " ";
      tenth(ss, num);
    }
  } else {
    tenth(ss, num);
  }
}

static void thousandth(std::stringstream& ss, int num) {
  if (num >= 1000) {
    hundredth(ss, num / 1000);
    ss << " Thousand";
    num %= 1000;
    if (num > 0) {
      ss << " ";
      hundredth(ss, num);
    }
  } else {
    hundredth(ss, num);
  }
}

static void millionth(std::stringstream& ss, int num) {
  if (num >= 1000000) {
    hundredth(ss, num / 1000000);
    ss << " Million";
    num %= 1000000;
    if (num > 0) {
      ss << " ";
      thousandth(ss, num);
    }
  } else {
    thousandth(ss, num);
  }
}

static void billionth(std::stringstream& ss, int num) {
  if (num >= 1000000000) {
    hundredth(ss, num / 1000000000);
    ss << " Billion";
    num %= 1000000000;
    if (num > 0) {
      ss << " ";
      millionth(ss, num);
    }
  } else {
    millionth(ss, num);
  }
}

class Solution {
 public:
  std::string numberToWords(int num) {
    if (num == 0) return "Zero";
    std::stringstream ss;
    billionth(ss, num);
    return ss.str();
  }
};
