#include "FineGrainedQueue.h"

int main()
{
    Node* a = new Node(11);
    Node* b = new Node(22);
    Node* c = new Node(33);
    Node* d = new Node(44);

    a->next = b;
    b->next = c;
    c->next = d;

    FineGrainedQueue* e = new FineGrainedQueue();
    e->head = a;

    std::cout << "BEFORE INSERT" << std::endl;
    e->showValues();

    std::thread t1([&]() {e->insertIntoMiddle(777, 1); });
    std::thread t2([&]() {e->insertIntoMiddle(99, 3); });
    e->insertIntoMiddle(0, 55);
    if (t1.joinable())t1.join();
    if (t2.joinable())t2.join();

    std::cout << std::endl;
    std::cout << "AFTER INSERT" << std::endl;
    e->showValues();

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    return 0;
}