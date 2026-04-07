#include <vector>

class Robot {
 public:
  Robot(int width, int height) {
    (void)width;
    (void)height;
  }

  void step(int num) {
    (void)num;
  }

  std::vector<int> getPos() {
    return {};
  }

  std::string getDir() {
    return {};
  }
};
