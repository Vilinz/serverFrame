#ifndef __VILIN_LOG_H__
#define __VILIN_LOG_H__

#include <iostream>
#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <stdarg.h>
#include <map>
#include "vilin/singleton.h"
#include "./../util.h"

#define VILIN_LOG_LEVEL(logger, level) \
	if(logger->getLevel() <= level) \
		vilin::LogEventWrap(vilin::LogEvent::ptr(new vilin::LogEvent(logger, level, __FILE__, __LINE__, 0, \
		vilin::GetThreadId(), vilin::GetFiberId(), time(0)))).getSS()

#define VILIN_LOG_DEBUG(logger) VILIN_LOG_LEVEL(logger, vilin::LogLevel::DEBUG)
#define VILIN_LOG_INFO(logger) VILIN_LOG_LEVEL(logger, vilin::LogLevel::INFO)
#define VILIN_LOG_WARN(logger) VILIN_LOG_LEVEL(logger, vilin::LogLevel::WARN)
#define VILIN_LOG_ERROR(logger) VILIN_LOG_LEVEL(logger, vilin::LogLevel::ERROR)
#define VILIN_LOG_FATAL(logger) VILIN_LOG_LEVEL(logger, vilin::LogLevel::FATAL)

#define VILIN_LOG_FMT_LEVEL(logger, level, fmt, ...) \
	if(logger->getLevel() <= level) \
		vilin::LogEventWrap(vilin::LogEvent::ptr(new vilin::LogEvent(logger, level, \
			__FILE__, __LINE__, 0, vilin::GetThreadId(), \
			vilin::GetFiberId(), time(0)))).getEvent()->format(fmt, __VA_ARGS__)

#define VILIN_LOG_FMT_DEBUG(logger, fmt, ...) VILIN_LOG_FMT_LEVEL(logger, vilin::LogLevel::DEBUG, fmt, __VA_ARGS__)
#define VILIN_LOG_FMT_INFO(logger, fmt, ...) VILIN_LOG_FMT_LEVEL(logger, vilin::LogLevel::INFO, fmt, __VA_ARGS__)
#define VILIN_LOG_FMT_WARN(logger, fmt, ...) VILIN_LOG_FMT_LEVEL(logger, vilin::LogLevel::WARN, fmt, __VA_ARGS__)
#define VILIN_LOG_FMT_ERROR(logger, fmt, ...) VILIN_LOG_FMT_LEVEL(logger, vilin::LogLevel::ERROR, fmt, __VA_ARGS__)
#define VILIN_LOG_FMT_FATAL(logger, fmt, ...) VILIN_LOG_FMT_LEVEL(logger, vilin::LogLevel::FATAL, fmt, __VA_ARGS__)

namespace vilin {

class Logger;

class LogLevel {
public:
	enum Level {
		UNKNOW = 0,
		DEBUG = 1,
		INFO = 2,
		WARN = 3,
		ERROR = 4,
		FATAL = 5
	};

	static const char* ToString(LogLevel::Level level);
};

class LogEvent {
public:
	typedef std::shared_ptr<LogEvent> ptr;
	LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level, const char* file, int32_t line, uint32_t elapse, uint32_t thread_id, uint32_t fiber_id, uint64_t time);

	const char* getFile() const { return m_file; }
	uint32_t getLine() const { return m_line; }
	uint32_t getElapse() const { return m_elapse; }
	uint32_t getThreadId() const { return m_threadId; }
	uint32_t getFiberId() const { return m_fiberId; }
	uint64_t getTime() const { return m_time; }
	std::string getContent() const { return m_ss.str(); }
	std::shared_ptr<Logger> getLogger() const { return m_logger; }
	LogLevel::Level getLevel() const { return m_level; }

	std::stringstream& getSS() { return m_ss; }

	void format(const char* fmt, ...);

	void format(const char* fmt, va_list al);
private:
	const char *m_file = nullptr;
	uint32_t m_line = 0;
	uint32_t m_elapse = 0;
	uint32_t m_threadId = 0;
	uint32_t m_fiberId = 0;
	uint64_t m_time;
	std::stringstream m_ss;

	std::shared_ptr<Logger> m_logger;
	LogLevel::Level m_level;
};

class LogEventWrap {
public:
	LogEventWrap(LogEvent::ptr e);
	~LogEventWrap();
	LogEvent::ptr getEvent() const { return m_event; }
	std::stringstream& getSS();
private:
	LogEvent::ptr m_event;
};

class LogFormatter {
public:
	typedef std::shared_ptr<LogFormatter> ptr;
	LogFormatter(const std::string& pattern);

	std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
	std::ostream& format(std::ostream& ofs, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
public:
	class FormatItem {
	public:
		typedef std::shared_ptr<FormatItem> ptr;
		FormatItem(const std::string& fmt = "") {}
		virtual ~FormatItem() {}
		virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
	};
	void init();

	bool isError() const { return m_error; }

	const std::string getPattern() const { return m_pattern; }
private:
	std::string m_pattern;
	std::vector<FormatItem::ptr> m_items;
	bool m_error = false;
};

class LogAppender {
friend class Logger;
public:
	typedef std::shared_ptr<LogAppender> ptr;
	virtual ~LogAppender() {}

	virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level, LogEvent::ptr event) = 0;

	void setFormatter(LogFormatter::ptr val);
	LogFormatter::ptr getFormatter() const;

	LogLevel::Level getLevel() const { return m_level; }
	void setLevel(LogLevel::Level val) { m_level = val; }
protected:
	LogLevel::Level m_level = LogLevel::DEBUG;
	bool m_hasFormatter = false;
	LogFormatter::ptr m_formatter;
};

class Logger : public std::enable_shared_from_this<Logger> {
friend class LoggerManager;
public:
	typedef std::shared_ptr<Logger> ptr;

	Logger(const std::string &name = "root");
	void log(LogLevel::Level level, LogEvent::ptr event);

	void debug(LogEvent::ptr event);
	void info(LogEvent::ptr event);
	void warn(LogEvent::ptr event);
	void error(LogEvent::ptr event);
	void fatal(LogEvent::ptr event);

	void addAppender(LogAppender::ptr appender);
	void delAppender(LogAppender::ptr appender);

	void clearAppenders();

	LogLevel::Level getLevel() const { return m_level; }
	void setLevel(LogLevel::Level val) { m_level = val; }

	const std::string& getName() const { return m_name; }

	void setFormatter(LogFormatter::ptr val);

	void setFormatter(const std::string& val);

	LogFormatter::ptr getFormatter();
private:
	std::string m_name;
	LogLevel::Level m_level;
	std::list<LogAppender::ptr> m_appenders;
	LogFormatter::ptr m_formatter;

	Logger::ptr m_root;
};

class StdoutLogAppender : public LogAppender {
public:
	typedef std::shared_ptr<StdoutLogAppender> ptr;
	void log(Logger::ptr logger, LogLevel::Level, LogEvent::ptr event) override;
};

class FileLogAppender : public LogAppender {
public:
	typedef std::shared_ptr<FileLogAppender> ptr;
	FileLogAppender(const std::string &filename);
	void log(Logger::ptr logger, LogLevel::Level, LogEvent::ptr event) override;

	bool reopen();
private:
	std::string m_filename;
	std::ofstream m_filestream;
	uint64_t m_lastTime = 0;
};

class LoggerManager {
public:
	LoggerManager();

	Logger::ptr getLogger(const std::string& name);
	void init();

	Logger::ptr getRoot() const { return m_root; }
private:
	std::map<std::string, Logger::ptr> m_loggers;
	Logger::ptr m_root;
};

typedef vilin::Singleton<LoggerManager> LoggerMgr;

}

#endif