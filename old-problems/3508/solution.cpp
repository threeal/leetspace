#include <algorithm>
#include <deque>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Router {
 private:
  std::size_t packetsLimit;
  std::queue<std::tuple<int, int, int>> packets;
  std::unordered_set<int64_t> packetExists;
  std::unordered_map<int, std::deque<int>> packetTimestamps;

 public:
  Router(int memoryLimit)
      : packetsLimit(memoryLimit),
        packets{},
        packetExists{},
        packetTimestamps{} {}

  bool addPacket(int source, int destination, int timestamp) {
    int64_t key{(int64_t)source << 40 | (int64_t)destination << 20 | timestamp};
    if (packetExists.contains(key)) return false;

    packets.push({source, destination, timestamp});
    packetExists.insert(key);
    packetTimestamps[destination].push_back(timestamp);

    if (packets.size() > packetsLimit) forwardPacket();

    return true;
  }

  std::vector<int> forwardPacket() {
    if (packets.empty()) return {};

    const auto [source, destination, timestamp] = packets.front();
    packets.pop();

    int64_t key{(int64_t)source << 40 | (int64_t)destination << 20 | timestamp};
    packetExists.erase(key);
    packetTimestamps[destination].pop_front();

    return {source, destination, timestamp};
  }

  int getCount(int destination, int startTime, int endTime) {
    const auto& timestamps = packetTimestamps[destination];
    return std::distance(
        std::lower_bound(timestamps.begin(), timestamps.end(), startTime),
        std::upper_bound(timestamps.begin(), timestamps.end(), endTime));
  }
};
