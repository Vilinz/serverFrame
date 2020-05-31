#include <iostream>
#include "vilin/log/log.h"

int main() {
	vilin::Logger::ptr logger(new vilin::Logger);
	logger->addAppender(vilin::LogAppender::ptr(new vilin::StdoutLogAppender));

	vilin::LogEvent::ptr event(new vilin::LogEvent(__FILE__, __LINE__, 0, 1, 2, time(0)));
	event->getSS() << "hello test";

	logger->log(vilin::LogLevel::DEBUG, event);
	return 0;
}