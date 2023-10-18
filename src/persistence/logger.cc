#include "logger.h"

namespace persistence {

Logger &Logger::GetInstance() {
  static Logger instance;
  return instance;
}

void Logger::AddLogRecord(const std::string& new_log_record) {
  log_.emplace_back(new_log_record);
}

void Logger::SaveLogToFile() {

}

}
