#include <vector>

extern "C" {
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize);
}

bool solution_c(std::vector<std::vector<int>> rooms) {
  std::vector<int*> roomsDatas(rooms.size());
  std::vector<int> roomsSizes(rooms.size());
  for (std::size_t i{0}; i < rooms.size(); ++i) {
    roomsDatas[i] = rooms[i].data();
    roomsSizes[i] = rooms[i].size();
  }

  return canVisitAllRooms(roomsDatas.data(), rooms.size(), roomsSizes.data());
}
