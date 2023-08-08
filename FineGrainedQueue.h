#pragma once
#include <iostream>
#include <thread>
#include <mutex>

struct Node
{
    Node(int value) : value(value), next(nullptr), node_mutex() {}
    int value;
    Node* next;
    std::mutex node_mutex;
};

class FineGrainedQueue
{
    std::mutex queue_mutex;
public:
    FineGrainedQueue() : head(nullptr), queue_mutex() {}
    Node* head;

    void insertIntoMiddle(const int& value, const int& pos);
    void showValues();
};