void markLeft(char** grid, int gridSize, int y, int x);
void markRight(char** grid, int gridSize, int y, int x);
void markTop(char** grid, int gridSize, int y, int x);
void markBottom(char** grid, int gridSize, int y, int x);

int regionsBySlashes(char** grid, int gridSize) {
  for (int i = gridSize - 1; i >= 0; --i) {
    for (char* c = grid[i]; *c != 0; ++c) {
      switch (*c) {
        case ' ':
          *c = 0b000000;
          break;
        case '/':
          *c = 0b000001;
          break;
        case '\\':
          *c = 0b000011;
          break;
      }
    }
  }

  int regions = 0;
  for (int y = gridSize - 1; y >= 0; --y) {
    for (int x = gridSize - 1; x >= 0; --x) {
      switch (grid[y][x] & 0b000011) {
        case 0b000000:
          if ((grid[y][x] & 0b111100) == 0b000000) {
            ++regions;
            grid[y][x] |= 0b111100;
            if (x > 0) markLeft(grid, gridSize, y, x - 1);
            if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
            if (y > 0) markTop(grid, gridSize, y - 1, x);
            if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
          }
          break;

        case 0b000001:
          if ((grid[y][x] & 0b101000) == 0b000000) {
            ++regions;
            grid[y][x] |= 0b101000;
            if (x > 0) markLeft(grid, gridSize, y, x - 1);
            if (y > 0) markTop(grid, gridSize, y - 1, x);
          }

          if ((grid[y][x] & 0b010100) == 0b000000) {
            ++regions;
            grid[y][x] |= 0b010100;
            if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
            if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
          }
          break;

        case 0b000011:
          if ((grid[y][x] & 0b100100) == 0b000000) {
            ++regions;
            grid[y][x] |= 0b100100;
            if (x > 0) markLeft(grid, gridSize, y, x - 1);
            if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
          }

          if ((grid[y][x] & 0b011000) == 0b000000) {
            ++regions;
            grid[y][x] |= 0b011000;
            if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
            if (y > 0) markTop(grid, gridSize, y - 1, x);
          }
          break;
      }
    }
  }

  return regions;
}

void markLeft(char** grid, int gridSize, int y, int x) {
  switch (grid[y][x] & 0b000011) {
    case 0b000000:
      if ((grid[y][x] & 0b111100) == 0b000000) {
        grid[y][x] |= 0b111100;
        if (x > 0) markLeft(grid, gridSize, y, x - 1);
        if (y > 0) markTop(grid, gridSize, y - 1, x);
        if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
      }
      break;

    case 0b000001:
      if ((grid[y][x] & 0b010100) == 0b000000) {
        grid[y][x] |= 0b010100;
        if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
      }
      break;

    case 0b000011:
      if ((grid[y][x] & 0b011000) == 0b000000) {
        grid[y][x] |= 0b011000;
        if (y > 0) markTop(grid, gridSize, y - 1, x);
      }
      break;
  }
}

void markRight(char** grid, int gridSize, int y, int x) {
  switch (grid[y][x] & 0b000011) {
    case 0b000000:
      if ((grid[y][x] & 0b111100) == 0b000000) {
        grid[y][x] |= 0b111100;
        if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
        if (y > 0) markTop(grid, gridSize, y - 1, x);
        if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
      }
      break;

    case 0b000001:
      if ((grid[y][x] & 0b101000) == 0b000000) {
        grid[y][x] |= 0b101000;
        if (y > 0) markTop(grid, gridSize, y - 1, x);
      }
      break;

    case 0b000011:
      if ((grid[y][x] & 0b100100) == 0b000000) {
        grid[y][x] |= 0b100100;
        if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
      }
      break;
  }
}

void markTop(char** grid, int gridSize, int y, int x) {
  switch (grid[y][x] & 0b000011) {
    case 0b000000:
      if ((grid[y][x] & 0b111100) == 0b000000) {
        grid[y][x] |= 0b111100;
        if (x > 0) markLeft(grid, gridSize, y, x - 1);
        if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
        if (y > 0) markTop(grid, gridSize, y - 1, x);
      }
      break;

    case 0b000001:
      if ((grid[y][x] & 0b010100) == 0b000000) {
        grid[y][x] |= 0b010100;
        if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
      }
      break;

    case 0b000011:
      if ((grid[y][x] & 0b100100) == 0b000000) {
        grid[y][x] |= 0b100100;
        if (x > 0) markLeft(grid, gridSize, y, x - 1);
      }
      break;
  }
}

void markBottom(char** grid, int gridSize, int y, int x) {
  switch (grid[y][x] & 0b000011) {
    case 0b000000:
      if ((grid[y][x] & 0b111100) == 0b000000) {
        grid[y][x] |= 0b111100;
        if (x > 0) markLeft(grid, gridSize, y, x - 1);
        if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
        if (y < gridSize - 1) markBottom(grid, gridSize, y + 1, x);
      }
      break;

    case 0b000001:
      if ((grid[y][x] & 0b101000) == 0b000000) {
        grid[y][x] |= 0b101000;
        if (x > 0) markLeft(grid, gridSize, y, x - 1);
      }
      break;

    case 0b000011:
      if ((grid[y][x] & 0b011000) == 0b000000) {
        grid[y][x] |= 0b011000;
        if (x < gridSize - 1) markRight(grid, gridSize, y, x + 1);
      }
      break;
  }
}
