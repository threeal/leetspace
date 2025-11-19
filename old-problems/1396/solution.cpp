#include <string>

class UndergroundSystem {
 public:
  UndergroundSystem() {}

  void checkIn(int id, std::string stationName, int t) {
    (void)id;
    (void)stationName;
    (void)t;
  }

  void checkOut(int id, std::string stationName, int t) {
    (void)id;
    (void)stationName;
    (void)t;
  }

  double getAverageTime(std::string startStation, std::string endStation) {
    return startStation.size() + endStation.size();
  }
};
