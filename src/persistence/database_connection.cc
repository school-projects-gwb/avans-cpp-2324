#include <iostream>
#include "database_connection.h"

namespace persistence {

DatabaseConnection &DatabaseConnection::GetInstance() {
  static DatabaseConnection instance;
  return instance;
}

void DatabaseConnection::ConnectToSqlite(const char *dbName) {
  if (connection_) return;

  try {
    connection_ = std::make_unique<SqliteConnectionWrapper>(dbName);
  } catch (const std::runtime_error &ex) {
    throw;
  }
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

void DatabaseConnection::ExecuteQuery(const char *sql) const {
  if (!connection_) return;

  int result = sqlite3_exec(connection_->GetConnection(), sql, nullptr, nullptr, nullptr);
  if (result != SQLITE_OK)
    throw std::runtime_error("Query is invalid!");
}

}
