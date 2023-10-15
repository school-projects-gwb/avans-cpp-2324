#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_SQLITE_CONNECTION_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_SQLITE_CONNECTION_H_

#include <sqlite3.h>

namespace persistence {

class SqliteConnection {
 public:
  explicit SqliteConnection(const char* dbName);
  ~SqliteConnection();
  sqlite3* GetConnection() const;
 private:
  sqlite3* connection;
  bool FileExists(const char* fileName) const;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_SQLITE_CONNECTION_H_
