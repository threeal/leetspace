#include <string>
#include <vector>

class OrderedStream {
 public:
  OrderedStream(int n) {
    (void)n;
  }

  std::vector<std::string> insert(int idKey, std::string value) {
    return std::vector(idKey, value);
  }
};
