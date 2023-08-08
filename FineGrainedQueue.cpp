#include "FineGrainedQueue.h"

    void FineGrainedQueue::insertIntoMiddle(const int& value, const int& pos)
    {
        // If the list is empty
        if (this->head == nullptr)
            return;

        // List start - position 0
        if (pos == 0)
            return;

        Node* prev, * cur;
        int countLong = 1;
        queue_mutex.lock();

        prev = this->head;
        cur = this->head->next;

        prev->node_mutex.lock();
        queue_mutex.unlock();

        if (cur)
            cur->node_mutex.lock();

        while (cur != nullptr)
        {
            // The element is inserted in the middle of the list
            if (pos == countLong)
            {
                Node* newNode = new Node(value);
                prev->next = newNode;
                newNode->next = cur;
                prev->node_mutex.unlock();
                cur->node_mutex.unlock();
                return;
            }
            if (cur->next == nullptr)
            {
                // If pos is greater than the length of the list, then insert the element at the end of the list
                Node* newNode = new Node(value);
                cur->next = newNode;

                prev->node_mutex.unlock();
                cur->node_mutex.unlock();

                return;
            }
            Node* old_prev = prev;
            prev = cur;
            cur = cur->next;
            old_prev->node_mutex.unlock();
            if (cur)
                cur->node_mutex.lock();
            countLong++;
        }
    }
    void FineGrainedQueue::showValues()
    {
        FineGrainedQueue* temp = new FineGrainedQueue();
        temp->head = this->head;
        while (temp->head)
        {
            std::cout << temp->head->value << std::endl;
            temp->head = temp->head->next;
        }
        delete temp;
    }