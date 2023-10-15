#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATABASE_CONNECTION_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATABASE_CONNECTION_H_

#include <sqlite3.h>
#include <memory>
#include "sqlite_connection.h"

namespace persistence {

class DatabaseConnection {
 public:
  static DatabaseConnection& GetInstance();
  DatabaseConnection(const DatabaseConnection&) = delete;
  DatabaseConnection& operator=(const DatabaseConnection&) = delete;
  bool ConnectToSqlite(const char* dbName);
  void ExecuteQuery(const char* sql);
 private:
  DatabaseConnection() = default;
  ~DatabaseConnection() = default;
  std::unique_ptr<SqliteConnection> connection_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATABASE_CONNECTION_H_
