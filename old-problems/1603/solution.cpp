class ParkingSystem {
 private:
  int spaces[4];

 public:
  ParkingSystem(int big, int medium, int small)
      : spaces{0, big, medium, small} {}

  bool addCar(int carType) {
    return --spaces[carType] >= 0;
  }
};
