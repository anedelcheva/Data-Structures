#include <iostream>
#include <iomanip>

#include "heap.h"

using namespace std;

template <typename V, typename P>
Heap<V,P>::Heap()
{
    size = 0;
    capacity = 1;
    container = new Pair<V,P>[capacity];
}

template <typename V, typename P>
Heap<V,P>::Heap(const Heap& other)
{
    copyHeap(other);
}

template <typename V, typename P>
Heap<V,P>& Heap<V,P>::operator=(const Heap& other)
{
    if(this != &other)
    {
        deleteHeap();
        copyHeap(other);
    }
    return *this;
}

template <typename V, typename P>
Heap<V,P>::~Heap()
{
    deleteHeap();
}

template <typename V, typename P>
void Heap<V,P>::insert(V v,P p)
{
    if(size == capacity)
        resize();
    Pair<V, P> pair;
    pair.value = v;
    pair.priority = p;
    container[size] = pair;
    size++;
    bubble(size-1);
}

template <typename V, typename P>
bool Heap<V,P>::pop(V& v)
{
    if(empty())
        return false;

    v = container[0].value;
    swapElements(0, size-1);
    size--;
    heapify(0);
    return true;
}

template <typename V, typename P>
bool Heap<V,P>::empty()const
{
    return size == 0;
}

template <typename V, typename P>
int Heap<V, P>::getSize()const
{
    return size;
}


template <typename V, typename P>
void Heap<V,P>::print()const
{
    if(!empty())
        for(int i = 0; i < size; i++)
            cout << "Value: "    << setw(8) << container[i].value    << endl
                 << "Priority: " << setw(5) << container[i].priority << endl;
}

template <typename V, typename P>
void Heap<V, P>::printPriority()const
{
    if(!empty())
    for(int i = 0; i < size; i++)
        cout << container[i].priority << " | ";
}

template <typename V, typename P>
V Heap<V, P>::maxPriority()const
{
    return container[0].value;
}

template <typename V, typename P>
void Heap<V, P>::heapify(int i)
{
    int l = leftChild(i), r = rightChild(i), largest = i;
//checks whether left child exists or not and whether left child is greater than parent
    if(l < size && container[largest].priority < container[l].priority)
        largest = l;
//checks whether right child exists or not and whether right child is greater than parent and left child
    if(r < size && container[largest].priority < container[r].priority)
        largest = r;
    if(i != largest)
    {
        swapElements(i, largest);
        heapify(largest);
    }
}

template <typename V, typename P>
void Heap<V,P>::deleteHeap()
{
    delete [] container;
}

template <typename V, typename P>
void Heap<V,P>::copyHeap(const Heap &other)
{
    size = other.size;
    capacity = other.capacity;
    container = new Pair<V,P>[capacity];
    for(int i = 0; i < size; i++)
        container[i] = other.container[i];
}

template <typename V, typename P>
void Heap<V,P>::resize()
{
    Pair<V,P> *oldContainer = container;
    capacity *= 2;
    container = new Pair<V,P>[capacity];
    for(int i = 0; i < size; i++)
        container[i] = oldContainer[i];
    delete [] oldContainer;
}

template <typename V, typename P>
void Heap<V,P>::swapElements(int i, int j)
{
    swap(container[i], container[j]);
}

template <typename V, typename P>
int Heap<V,P>::leftChild(int index)const
{
    return 2*index + 1;
}

template <typename V, typename P>
int Heap<V,P>::rightChild(int index)const
{
    return 2*index + 2;
}

template <typename V, typename P>
int Heap<V,P>::parent(int index)const
{
    return (index-1)/2;
}

template <typename V, typename P>
void Heap<V,P>::bubble(int index)
{

    while(index != 0)
    {
        int p = parent(index);
        if(container[p].priority < container[index].priority)
        {
            swapElements(p, index);
            index = p;
        }
        else
            break;
    }
}

/*int main()
{
    cout << "H E A P\n\n";
    Heap<int, float> heap; // int for faculty number and float for grade
    cout << "Is heap empty: " << boolalpha << heap.empty() << endl << endl;

    heap.insert(81061,5.5);
    heap.insert(81067, 4.5);
    heap.insert(81045, 6);
    heap.insert(910555, 5);
    heap.insert(80505, 5.25);

    cout << "Elements in heap: ";
    heap.printPriority();

    cout << "\nSize of heap: " << heap.getSize() << endl;
    cout << "\nValue of the element with max priority in the heap: " << heap.maxPriority() << endl;
    int v;
    cout << "\nIs element from the heap popped: " << heap.pop(v) << endl;
    cout << "\nValue of the element with max priority removed: " << v << endl << endl;
    heap.print();
}*/
