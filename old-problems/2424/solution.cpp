#include <vector>

class LUPrefix {
 private:
  std::vector<bool> uploaded;
  int prefix;

 public:
  LUPrefix(int n) : uploaded(n + 2, false), prefix{0} {}

  void upload(int video) {
    uploaded[video] = true;
    while (uploaded[++prefix]) {
    }
    --prefix;
  }

  int longest() {
    return prefix;
  }
};
