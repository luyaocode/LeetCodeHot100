#pragma once
#include <string>
#include <mutex>
#include <condition_variable>

class Solution001
{
public:
	Solution001() :turn(0) {}
	/**
	* 三个线程 ThreadA、ThreadB、ThreadC，分别会打印 A、B、C，
	* 要求让三个线程循环交替执行，在控制台打印 ABCABCABC……
	*/
	void printID(std::string id,int n);
	void multithreadLoopPrintABC();
	void test();
private:
	const int  MAX_SIZE = 100;
	std::mutex mutex;
	std::condition_variable cv;
	int turn;
};