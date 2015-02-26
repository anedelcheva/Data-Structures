#include <iostream>
using namespace std;

#include "heap.cpp"
#include "PriorityQueue.h"

template<typename V, typename P>
void PriorityQueue<V, P>::insert(V v, P p)
{
    queue.insert(v, p);
}

template<typename V, typename P>
bool PriorityQueue<V, P>::pop(V& v)
{
    return queue.pop(v);
}

template<typename V, typename P>
V PriorityQueue<V, P>::peek()const
{
    return queue.maxPriority();
}

template<typename V, typename P>
bool PriorityQueue<V, P>::empty()const
{
    return queue.empty();
}

template <typename V, typename P>
void PriorityQueue<V,P>::print()const
{
    queue.print();
}

template <typename V, typename P>
void PriorityQueue<V,P>::printPriority()const
{
    queue.printPriority();
}

/*int main()
{
    cout << "\n\nPRIORITY QUEUE\n\n";
    PriorityQueue<int, float> queue;
    queue.insert(81061, 5.5);
    queue.insert(81042, 6);
    queue.insert(81063, 4);
    queue.insert(810555, 4.5);
    queue.insert(81574, 5.25);
    cout << "\nElements in the priority queue: \n";
    queue.print();
    cout << "\nValue of the element with max priority (peek): " << queue.peek() << endl;
    cout << "Popping the element with max priority: ";
    int v;
    cout << queue.pop(v);
    cout << endl << "Value of the element with max priority (pop): " << v << endl << endl;
    queue.print();

    queue.insert(87294, 7);
    cout << endl;
    queue.printPriority();
    cout << endl;
    return 0;
}*/

