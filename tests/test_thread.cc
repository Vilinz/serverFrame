#include "vilin/vilin.h"
#include <iostream>
#include <thread>

vilin::Logger::ptr g_logger = VILIN_LOG_ROOT();

int count = 0;
//vilin::RWMutex s_mutex;
vilin::Mutex s_mutex;

void fun1() {
	VILIN_LOG_INFO(g_logger) << "name: " << vilin::Thread::GetName()
													 << " this.name: " << vilin::Thread::GetThis()->getName()
													 << " id: " << vilin::GetThreadId()
													 << " this.id: " << vilin::Thread::GetThis()->getId();

	for(int i = 0; i < 10000; i++) {
		// vilin::RWMutex::WriteLock lock(s_mutex);
		vilin::Mutex::Lock lock(s_mutex);
		++count;
	}
}

void fun2() {
	while(true) {
		VILIN_LOG_INFO(g_logger) << "xxxxxxxxxxxxxxxxxxxxxxxxx";
	}
}

void fun3() {
	while(true) {
		VILIN_LOG_INFO(g_logger) << "=========================";
	}
}

int main () {
	VILIN_LOG_INFO(g_logger) << "thread test begin";
	YAML::Node root = YAML::LoadFile("/home/vilingif/Desktop/serverFrame/bin/conf/log2.yml");
	vilin::Config::LoadFromYaml(root);

	VILIN_LOG_INFO(g_logger) << "=========================";

	std::vector<vilin::Thread::ptr> thrs;
	for(int i = 0; i < 2; ++i) {
		vilin::Thread::ptr thr(new vilin::Thread(&fun2, "name_" + std::to_string(i * 2)));
		vilin::Thread::ptr thr2(new vilin::Thread(&fun3, "name_" + std::to_string(i * 2 + 1)));
		thrs.push_back(thr);
		thrs.push_back(thr2);
	}

	for(size_t i = 0; i < thrs.size(); ++i) {
		thrs[i]->join();
	}
	
	VILIN_LOG_INFO(g_logger) << "thread test end";
	VILIN_LOG_INFO(g_logger) << "count: " << count;

	return 0;
}