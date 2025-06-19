#include <string>

class BrowserHistory {
 public:
  BrowserHistory(std::string homepage) {
    (void)homepage;
  }

  void visit(std::string url) {
    (void)url;
  }

  std::string back(int steps) {
    (void)steps;
    return "";
  }

  std::string forward(int steps) {
    (void)steps;
    return "";
  }
};
