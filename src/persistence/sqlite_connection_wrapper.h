#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_SQLITE_CONNECTION_WRAPPER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_SQLITE_CONNECTION_WRAPPER_H_

#include <sqlite3.h>

namespace persistence {

class SqliteConnectionWrapper {
 public:
  explicit SqliteConnectionWrapper(const char* dbName);
  ~SqliteConnectionWrapper();
  // Delete other operations
  SqliteConnectionWrapper(const SqliteConnectionWrapper&) = delete;
  SqliteConnectionWrapper& operator=(const SqliteConnectionWrapper&) = delete;
  SqliteConnectionWrapper(SqliteConnectionWrapper&&) = delete;
  SqliteConnectionWrapper& operator=(SqliteConnectionWrapper&&) = delete;

  sqlite3* GetConnection() const;
 private:
  sqlite3* connection_;
  bool FileExists(const char* fileName) const;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_SQLITE_CONNECTION_WRAPPER_H_
