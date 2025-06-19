#include <string>
#include <vector>

class BrowserHistory {
 private:
  std::vector<std::string> urls;
  int current;

 public:
  BrowserHistory(std::string homepage) : urls{{homepage}}, current{0} {}

  void visit(std::string url) {
    ++current;
    urls.resize(current);
    urls.push_back(url);
  }

  std::string back(int steps) {
    if (steps > current) {
      current = 0;
    } else {
      current -= steps;
    }
    return urls[current];
  }

  std::string forward(int steps) {
    if (static_cast<std::size_t>(current + steps) >= urls.size()) {
      current = urls.size() - 1;
    } else {
      current += steps;
    }
    return urls[current];
  }
};
