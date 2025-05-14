#include <string>
#include <vector>

class OrderedStream {
 private:
  std::vector<std::string> streams;
  int i;

 public:
  OrderedStream(int n) : streams(n + 2), i{1} {}

  std::vector<std::string> insert(int idKey, std::string value) {
    if (i != idKey) {
      streams[idKey] = value;
      return {};
    }

    std::vector<std::string> output{value};
    ++i;

    while (!streams[i].empty()) {
      output.push_back(streams[i]);
      ++i;
    }

    return output;
  }
};
