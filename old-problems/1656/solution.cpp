#include <queue>
#include <string>
#include <tuple>
#include <vector>

class OrderedStream {
 private:
  using Stream = std::tuple<int, std::string>;
  std::priority_queue<Stream, std::vector<Stream>, std::greater<Stream>> queue;
  int i;

 public:
  OrderedStream(int /*n*/) : i{1} {}

  std::vector<std::string> insert(int idKey, std::string value) {
    std::vector<std::string> output{};
    if (i == idKey) {
      output.push_back(value);
      ++i;
    } else {
      queue.push({idKey, value});
    }

    while (!queue.empty() && std::get<0>(queue.top()) == i) {
      output.push_back(std::get<1>(queue.top()));
      queue.pop();
      ++i;
    }

    return output;
  }
};
