#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

// the struct Pair contains priority and value of an element
template <typename V, typename P>
struct Pair
{
    V value;    // value of the pair
    P priority; // priority of the pair
};

template <typename V, typename P>
class Heap
{
public:
    Heap();
    Heap(const Heap& other);
    Heap& operator = (const Heap& other);
    ~Heap();

    void insert(V, P);
    bool pop(V& v);
    bool empty() const;

    void printPriority()const;
    void print()const;

    V maxPriority()const;
    int getSize()const;

private:
    void bubble(int index);
    void heapify(int i);// equivalent of sink
    int leftChild(int index) const;
    int rightChild(int index) const;
    int parent(int index) const;
    void swapElements(int i, int j);

    void copyHeap(const Heap& other);
    void deleteHeap();
    void resize();


    Pair<V,P>* container;
    int size;
    int capacity;
};

#endif // HEAP_H_INCLUDED
