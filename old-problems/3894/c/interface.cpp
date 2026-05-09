#include <string>

extern "C" {
char* trafficSignal(int timer);
}

std::string solution_c(int timer) {
  return trafficSignal(timer);
}
