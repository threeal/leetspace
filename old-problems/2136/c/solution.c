int earliestFullBloom(
    int* plantTime, int plantTimeSize, int* growTime, int growTimeSize) {
  return plantTime[plantTimeSize - 1] + growTime[growTimeSize - 1];
}
