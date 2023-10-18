#include "database_connection.h"

namespace persistence {

DatabaseConnection &DatabaseConnection::GetInstance() {
  static DatabaseConnection instance;
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

std::unique_ptr<sqlite3_stmt, void(*)(sqlite3_stmt*)> DatabaseConnection::PrepareStatement(const char* sql) {
  if (!connection_) return std::unique_ptr<sqlite3_stmt, void(*)(sqlite3_stmt*)>(nullptr, nullptr);

  sqlite3_stmt* statement = nullptr;

  int result = sqlite3_prepare_v2(connection_->GetConnection(), sql, -1, &statement, nullptr);

  if (result != SQLITE_OK) {
    const char* errmsg = sqlite3_errmsg(connection_->GetConnection());
    throw std::runtime_error(errmsg);
  }

  auto statement_deleter = [](sqlite3_stmt* stmt) { sqlite3_finalize(stmt); };
  return std::unique_ptr<sqlite3_stmt, decltype(statement_deleter)>(statement, statement_deleter);
}

void DatabaseConnection::ExecuteQuery(const char *sql) {
  if (!connection_) return;

  int result = sqlite3_exec(connection_->GetConnection(), sql, nullptr, nullptr, nullptr);
  if (result != SQLITE_OK) {
    // todo error handling
  }
}

}
