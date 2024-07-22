// LeetCodeHot100.cpp: 定义应用程序的入口点。
//

#include "LeetCodeHot100_146.h"

int main()
{
	LRUCache lRUCache(1);
	lRUCache.put(2, 1);
	auto r1 = lRUCache.get(2);
	lRUCache.put(3, 2);
	auto r2=lRUCache.get(2);
	auto r3=lRUCache.get(3); 
	return 0;
}
