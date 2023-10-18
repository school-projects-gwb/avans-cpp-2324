#ifndef ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_LOGGER_H_
#define ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_LOGGER_H_

#include <vector>
#include <string>

namespace persistence {

class Logger {
 public:
  static Logger& GetInstance();
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  void AddLogRecord(const std::string& new_log_record);
  void SaveLogToFile();
 private:
  Logger() = default;
  ~Logger() = default;
  std::vector<std::string> log_;
};

}

#endif //ASSESSMENT_CPLUS_23_24_GUNWUNBUN_SRC_PERSISTENCE_LOGGER_H_
