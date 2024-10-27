#include <string>

class Solution {
 public:
  bool parseBoolExpr(std::string expression) {
    char* c{expression.data()};
    return parse(c);
  }

 private:
  static bool parse(char*& c) {
    if (*c == 't') {
      ++c;
      return true;
    }

    if (*c == 'f') {
      ++c;
      return false;
    }

    if (*c == '!') {
      c += 2;
      const bool b{!parse(c)};
      ++c;
      return b;
    }

    if (*c == '&') {
      bool b{true};
      ++c;
      while (*c != ')') {
        ++c;
        b &= parse(c);
      }
      ++c;
      return b;
    }

    bool b{false};
    ++c;
    while (*c != ')') {
      ++c;
      b |= parse(c);
    }
    ++c;
    return b;
  }
};
