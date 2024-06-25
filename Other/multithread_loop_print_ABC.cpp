#include "multithread_loop_print_ABC.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

void Solution001::printID(std::string id, int n)
{
	std::unique_lock<std::mutex> lock(mutex);
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		cv.wait(lock, [&n, this] { return n == this->turn; });
		std::cout << id;
		turn = (turn + 1) % 3;
		cv.notify_all();
	}
}

void Solution001::multithreadLoopPrintABC()
{
	std::thread threadA(&Solution001::printID, this, "A", 0);
	std::thread threadB(&Solution001::printID, this,"B", 1);
	std::thread threadC(&Solution001::printID, this,"C", 2);
	threadA.join();
	threadB.join();
	threadC.join();
}

void Solution001::test()
{
	multithreadLoopPrintABC();
}