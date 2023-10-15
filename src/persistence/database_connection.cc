#include "database_connection.h"

namespace persistence {

DatabaseConnection &DatabaseConnection::GetInstance() {
  static DatabaseConnection instance; // Singleton instance
  return instance;
}

bool DatabaseConnection::ConnectToSqlite(const char *dbName) {
  if (connection_) return true;

  try {
    connection_ = std::make_unique<SqliteConnection>(dbName);
  } catch (std::runtime_error &ex) {
    throw;
  }

  return true;
}

void DatabaseConnection::ExecuteQuery(const char *sql) {
  if (!connection_) return;

  int result = sqlite3_exec(connection_->GetConnection(), sql, nullptr, nullptr, nullptr);
  if (result != SQLITE_OK) {
    // Handle query execution error, e.g., log the error
  }
}

}
