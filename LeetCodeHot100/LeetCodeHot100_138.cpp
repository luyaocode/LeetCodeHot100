#include "LeetCodeHot100_138.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;
using std::unordered_map;
using std::vector;

Node* Solution138::copyRandomList(Node* head)
{
	// 1.��ʼ���ڵ�-������random����
	auto p = head;
	unordered_map<Node*,int> nodeIdxs;	// ԭ����Ľڵ�-������
	vector<int> rands;					// ԭ�����random����
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

	// 2.����������
	p = head;
	vector<Node*> nodes;		// ������Ľڵ�����
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

	// 3. ����random
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