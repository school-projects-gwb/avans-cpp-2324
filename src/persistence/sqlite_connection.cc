#include <iostream>
#include <fstream>
#include "sqlite_connection.h"

namespace persistence {

SqliteConnection::SqliteConnection(const char *dbName) {
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

SqliteConnection::~SqliteConnection() {
  if (connection_) sqlite3_close(connection_);
}

sqlite3 *SqliteConnection::GetConnection() const {
  return connection_;
}

bool SqliteConnection::FileExists(const char *fileName) const {
  std::ifstream file(fileName);
  return file.good();
}

}



