#ifndef __VILIN_THREAD_H__
#define __VILIN_THREAD_H__

//c++ before pthread
//c++11 std::thread pthread
#include <thread>
#include <functional>
#include <memory>

namespace vilin{

class Thread {
public:
	typedef std::shared_ptr<Thread> ptr;
	Thread(std::function<void()> cb, const std::string& name);
	~Thread();
private:
	Thread(const Thread&) = delete;
	Thread(const Thread&) = delete;
	Thread operator=(const Thread&) = delete;
private:
	tid_t m_id;
	pthread_t m_thread;
	std::function<void()> m_cb;
	std::string m_name;
};

}

#endif