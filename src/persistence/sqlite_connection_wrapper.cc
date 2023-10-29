#include <iostream>
#include <fstream>
#include "sqlite_connection_wrapper.h"

namespace persistence {

SqliteConnectionWrapper::SqliteConnectionWrapper(const char *dbName) {
  if (!FileExists(dbName)) throw std::runtime_error("Database file does not exist");

  int error = sqlite3_open(dbName, &connection_);
  if (error) {
    if (connection_) {
      sqlite3_close(connection_);
      connection_ = nullptr;
    }

    throw std::runtime_error("Database connection failed");
  }
}

SqliteConnectionWrapper::~SqliteConnectionWrapper() {
  if (connection_) sqlite3_close(connection_);
}

sqlite3 *SqliteConnectionWrapper::GetConnection() const {
  return connection_;
}

bool SqliteConnectionWrapper::FileExists(const char *fileName) const {
  std::ifstream file(fileName);
  return file.good();
}

}



