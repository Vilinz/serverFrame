#include <iostream>
#include <thread>
#include "vilin/log/log.h"
#include "vilin/util.h"

int main() {
	vilin::Logger::ptr logger(new vilin::Logger);
	logger->addAppender(vilin::LogAppender::ptr(new vilin::StdoutLogAppender));

	vilin::FileLogAppender::ptr file_appender(new vilin::FileLogAppender("./log.txt"));

	vilin::LogFormatter::ptr fmt(new vilin::LogFormatter("%d%T%m%n"));
	file_appender->setFormatter(fmt);
	file_appender->setLevel(vilin::LogLevel::ERROR);

	logger->addAppender(file_appender);

	// vilin::LogEvent::ptr event(new vilin::LogEvent(__FILE__, __LINE__, 0, vilin::GetThreadId(), vilin::GetFiberId(), time(0)));
	// event->getSS() << "hello test";

	// logger->log(vilin::LogLevel::DEBUG, event);

	VILIN_LOG_INFO(logger) << "test info";
	VILIN_LOG_ERROR(logger) << "test error";

	VILIN_LOG_FMT_ERROR(logger, "test fmt error %s", "aa");

	auto l = vilin::LoggerMgr::GetInstance()->getLogger("xx");
	VILIN_LOG_INFO(l) << "xxx";
	return 0;
}