#pragma once
#include <unordered_map>
using std::unordered_map;

struct MyListNode
{
    int val;
    int key; // �����map��ɾ����ֵ��
    MyListNode* front;
    MyListNode* next;
    MyListNode() :val(-1), key(-1), front(nullptr), next(nullptr) {}
    MyListNode(int v) :val(v), key(0),front(nullptr), next(nullptr) {}
    MyListNode(int v,int k) :val(v), key(k),front(nullptr), next(nullptr) {}
};

struct LinkedList
{
    // �����ưͽڵ㷽�����������Ҫ�ж������Ƿ�Ϊ��
    MyListNode* hair; // ͷ���ưͽڵ�
    MyListNode* tair; // β���ưͽڵ�
};

class LRUCache
{
private:
    int m_capacity;
    LinkedList m_list;
    unordered_map<int,MyListNode* > m_map;
public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        m_list.hair = new MyListNode();
        m_list.tair = new MyListNode();
        m_list.hair->next = m_list.tair;
        m_list.tair->front = m_list.hair;
    }

    int get(int key)
    {
        if (m_map.find(key) == m_map.end())
        {
            return -1;
        }
        moveToHead(m_map[key]);
        return m_map[key]->val;
    }

    void put(int key, int value)
    {
        if (m_map.find(key) != m_map.end())
        {
            m_map[key]->val = value;
            moveToHead(m_map[key]);
            return;
        }
        if (m_map.size() == m_capacity)
        {
            // ɾ��β��
            auto tairNode = m_list.tair->front;
            m_map.erase(tairNode->key);
            tairNode->front->next = m_list.tair;
            m_list.tair->front = tairNode->front;
            delete tairNode;
            tairNode = nullptr;
        }
        // ͷ������
        auto newNode = new MyListNode(value,key);
        auto oldHead = m_list.hair->next;
        m_list.hair->next = newNode;
        newNode->front = m_list.hair;
        newNode->next = oldHead;
        oldHead->front = newNode;
        m_map[key] = newNode;
    }

    /**
    * ���ڵ��Ƶ�ͷ��
    */
    void moveToHead(MyListNode* node)
    {
        auto oldHead = m_list.hair->next;
        if (node ==oldHead) // ����ڵ��Ѿ���ͷ���Ͳ���Ҫ�ƶ�
        {
            return;
        }
        auto oldFront = node->front;
        auto oldNext = node->next;
        m_list.hair->next = node;
        node->front = m_list.hair;
        node->next = oldHead;
        oldHead->front = node;
        oldNext->front = oldFront;
        oldFront->next = oldNext;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */