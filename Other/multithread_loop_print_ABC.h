#pragma once
#include <string>
#include <mutex>
#include <condition_variable>

class Solution001
{
public:
	Solution001() :turn(0) {}
	/**
	* �����߳� ThreadA��ThreadB��ThreadC���ֱ���ӡ A��B��C��
	* Ҫ���������߳�ѭ������ִ�У��ڿ���̨��ӡ ABCABCABC����
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