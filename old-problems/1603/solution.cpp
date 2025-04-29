class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small) {
    (void)big;
    (void)medium;
    (void)small;
  }

  bool addCar(int carType) {
    return carType == 0;
  }
};
