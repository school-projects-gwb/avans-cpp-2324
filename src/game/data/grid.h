#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_GRID_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_GRID_H_

#include <vector>

template <typename T>
using Grid = std::vector<std::vector<T>>;

template <typename T, size_t rows, size_t cols>
Grid<T> MultiDimensionalArrayToGrid(const T (&multiArray)[rows][cols]) {
  Grid<T> grid(rows, std::vector<T>(cols));

  for (size_t row = 0; row < rows; row++)
    for (size_t col = 0; col < cols; col++)
      grid[row][col] = multiArray[row][col];

  return grid;
}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_GRID_H_