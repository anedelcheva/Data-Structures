#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

template<typename V, typename P>
class PriorityQueue
{
public:
    void insert(V, P);
    bool pop(V&);
    V peek()const;
    bool empty()const;
    void print()const;
    void printPriority()const;

private:
    Heap<V,P> queue;
};

#endif // PRIORITYQUEUE_H_INCLUDED
