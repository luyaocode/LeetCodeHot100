#pragma once
#include <cstddef>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution142
{
public:
    /**
    * 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
    * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
    * 不允许修改 链表。
    */
    /**
    * 1.关于为什么快慢指针一定会在第一圈相遇？这里是一个容易理解的版本： 
    * 假设入环的第一个节点是链表的首节点，那么当慢指针走完一圈时，快指针刚好走完两圈，两者会在链表末尾极限相遇。
    * 随着入环的第一个节点往后推移，当慢指针刚好走到入环第一个节点时，快指针必然在入环n个节点(0<n)，也就是快指针比慢指针起步早n个节点，那么在慢指针走到环的末尾之前，快指针必然会赶上慢指针。 
    * 2.怎么求出入环第一个节点？ 
    * 假设链表首节点到入环第一个节点相距a，快慢指针第一次相遇时到入环第一个节点距离为n，环的总长度为N，那么由1易得，a+n=2(a+n)-N也就是a=N-n。
    * 然后让慢指针和头指针以相同的速度前进，那么当头指针走了距离a，走到了入环第一个节点时，慢指针走了N-n，也就是走回到了入环第一个节点，也就是说慢指针和头指针首次相遇在入环第一个节点。
    */
    ListNode* detectCycle(ListNode* head);   
    ListNode* detectCycle_A(ListNode* head); //空间复杂度O(1)
    void test();
};