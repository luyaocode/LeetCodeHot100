#include "LeetCodeHot100_138.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::unordered_map;
using std::vector;

Node* Solution138::copyRandomList(Node* head)
{
	// 1.初始化节点-索引表、random数组
	auto p = head;
	unordered_map<Node*,int> nodeIdxs;	// 原链表的节点-索引表
	vector<int> rands;					// 原链表的random数组
	int i{0};
	while (p != NULL)
	{
		nodeIdxs.emplace(p,i);
		p = p->next;
		++i;
	}
	p = head;
	while (p != NULL)
	{
		rands.emplace_back(p->random == NULL ? -1 : nodeIdxs[p->random]);
		p = p->next;
	}

	// 2.构造新链表
	p = head;
	vector<Node*> nodes;		// 新链表的节点数组
	Node* q = NULL;
	Node* newHead = NULL;
	i = 0;
	while (p != NULL)
	{
		Node* node = new Node(p->val);
		if (q == NULL)
		{
			q = node;
			newHead = node;
		}
		else
		{
			q->next = node;
			q = node;
		}
		nodes.emplace_back(node);
		p = p->next;
		++i;
	}

	// 3. 处理random
	q = newHead;
	i = 0;
	while (q != NULL)
	{
		Node* prand = rands[i]==-1?NULL:nodes[rands[i]];
		q->random = prand;

		q = q->next;
		++i;
	}
	return newHead;
}

void Solution138::test()
{

}