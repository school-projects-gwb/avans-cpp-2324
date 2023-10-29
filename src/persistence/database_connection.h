#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATABASE_CONNECTION_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATABASE_CONNECTION_H_

#include <sqlite3.h>
#include <memory>
#include "sqlite_connection_wrapper.h"

namespace persistence {

class DatabaseConnection {
 public:
  static DatabaseConnection& GetInstance();
  DatabaseConnection(const DatabaseConnection&) = delete;
  DatabaseConnection& operator=(const DatabaseConnection&) = delete;
  void ConnectToSqlite(const char* dbName);
  void ExecuteQuery(const char* sql) const;
  std::unique_ptr<sqlite3_stmt, void (*)(sqlite3_stmt *)> PrepareStatement(const char *sql);
 private:
  DatabaseConnection() = default;
  ~DatabaseConnection() = default;
  std::unique_ptr<SqliteConnectionWrapper> connection_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_DATABASE_CONNECTION_H_
