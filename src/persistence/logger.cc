#include "logger.h"
#include <fstream>
#include <ctime>
#include <sstream>
#include <iostream>

namespace persistence {

Logger &Logger::GetInstance() {
  static Logger instance;
  return instance;
}

void Logger::AppendLogRecord(const std::string& new_log_record) {
  log_.emplace_back(new_log_record);
}

void Logger::SaveLogToFile() {
  // Create and open file with current timestamp in its name
  std::time_t t = std::time(nullptr);
  std::tm tm = *std::localtime(&t);

  std::stringstream timestamp;
  timestamp << std::put_time(&tm, "%Y%m%d_%H%M%S");

  std::string filename = "game_log_" + timestamp.str() + ".txt";

  std::ofstream file(filename);

  // Write the actual log data to file
  if (file.is_open()) {
    for (const std::string& entry : log_)
      file << entry;

    file.close();
  } else {
    std::cerr << "Failed to open log file for writing." << std::endl;
  }

  log_.clear();
}

}
