int minProcessingTime(
    int* processorTime, int processorTimeSize, int* tasks, int tasksSize) {
  return processorTime[processorTimeSize - 1] + tasks[tasksSize - 1];
}
