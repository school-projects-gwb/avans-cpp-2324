#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_GRID_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_GRID_H_

#include <vector>
#include "coords.h"

template <typename T>
class Grid {
 public:
  Grid(size_t rows, size_t cols)
      : grid_(rows, std::vector<T>(cols)) {}

  Grid() = default;

  T& operator()(size_t row, size_t col) {
    return grid_[row][col];
  }

  const T& operator()(size_t row, size_t col) const {
    return grid_[row][col];
  }

  T& operator[](const Coords& coords) {
    return grid_[coords.pos_y_][coords.pos_x_];
  }

  const T& operator[](const Coords& coords) const {
    return grid_[coords.pos_y_][coords.pos_x_];
  }

  using iterator = typename std::vector<std::vector<T>>::iterator;
  using const_iterator = typename std::vector<std::vector<T>>::const_iterator;

  iterator begin() {
    return grid_.begin();
  }

  iterator end() {
    return grid_.end();
  }

  const_iterator begin() const {
    return grid_.begin();
  }

  const_iterator end() const {
    return grid_.end();
  }

  size_t GetRowCount() const {
    return grid_.size();
  }

  size_t ColColCount() const {
    return grid_.empty() ? 0 : grid_[0].size();
  }

  void Resize(size_t rows, size_t cols, const T& defaultValue = T()) {
    grid_.resize(rows, std::vector<T>(cols, defaultValue));
  }

 private:
  std::vector<std::vector<T>> grid_;
};


#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_GAME_DATA_GRID_H_