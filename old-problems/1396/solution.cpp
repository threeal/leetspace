#include <string>
#include <unordered_map>

struct Time {
  int total;
  int count;
};

struct Passenger {
  std::string stationName;
  int t;
};

class UndergroundSystem {
 private:
  std::unordered_map<std::string, std::unordered_map<std::string, Time>> times;
  std::unordered_map<int, Passenger> passengers;

 public:
  UndergroundSystem() : times{}, passengers{} {}

  void checkIn(int id, std::string stationName, int t) {
    auto& passenger = passengers[id];
    passenger.stationName = stationName;
    passenger.t = t;
  }

  void checkOut(int id, std::string stationName, int t) {
    const auto& passenger = passengers[id];
    auto& time = times[passenger.stationName][stationName];
    time.total += t - passenger.t;
    ++time.count;
  }

  double getAverageTime(std::string startStation, std::string endStation) {
    const auto& time = times[startStation][endStation];
    return time.count != 0 ? static_cast<double>(time.total) / time.count : 0;
  }
};
