#pragma once
#include <cstddef>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution138
{
public:
    Node* copyRandomList(Node* head);
    void test();
};