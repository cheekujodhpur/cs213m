#include <iostream>

#define MAX_SIZE 1000000

template<class T>
void swap(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<class T>
class MinMaxHeap
{
    T heap[MAX_SIZE];
    int size;


    void BubbleUpMin(int i);
    void BubbleUpMax(int i);
    public:
        /* This is a constructor */
        MinMaxHeap();
        /* Insert an object in the heap. O(log n) */
        void insert(T elem);
        /* Delete the minimum of the objects currently in the heap. O(log n) */
        void deleteMin();
        /*Delete the maximum of the objects currently in the heap. O(log n) */
        void deleteMax();
        /*Return the minimum of the objects */
        T getMin();
        /*Return the maximum of the objects */
        T getMax();
        /*The pred class defines a function toDelete with the signature bool toDelete(T). The function deleteElems then will delete from the min-max heap, all the elements such that toDelete returns true when called on them*/
        //void deleteElems(pred predObject);
        void print();
};

template<class T>
MinMaxHeap<T>::MinMaxHeap()
{
    size = 0;
}

template<class T>
void MinMaxHeap<T>::insert(T elem)
{ /*insert ahead and increment size*/
    size++;
    heap[size] = elem;
    
    int level = 0,heapSize = size;
    while(heapSize)
    {
        heapSize = (heapSize >> 1);
        level++;
    }
    /*to start from 0*/
    level--;
    
    /*if on a min level*/
    if(level%2==0)
    {
        if(size/2 >= 1)
        {
            if(heap[size]>heap[size/2])
            {
                swap(heap[size],heap[size/2]);
                BubbleUpMax(size/2);
            }
            else
                BubbleUpMin(size);
        }

    }
    else
    {
        if(size/2 >= 1)
        {
            if(heap[size]<heap[size/2])
            {
                swap(heap[size],heap[size/2]);
                BubbleUpMin(size/2);
            }
            else
                BubbleUpMax(size);
        }
    } 
}

template<class T>
void MinMaxHeap<T>::BubbleUpMin(int i)
{
    if((i/2)/2 >= 1)
    {
        if(heap[i]<heap[(i/2)/2])
        {
            swap(heap[i],heap[(i/2)/2]);
            BubbleUpMin((i/2)/2);
        }
    }
}

template<class T>
void MinMaxHeap<T>::BubbleUpMax(int i)
{
    if((i/2)/2 >= 1)
    {
        if(heap[i]>heap[(i/2)/2])
        {
            swap(heap[i],heap[(i/2)/2]);
            BubbleUpMax((i/2)/2);
        }
    }
}

template<class T>
void MinMaxHeap<T>::deleteMin()
{
    return;
}

template<class T>
void MinMaxHeap<T>::deleteMax()
{
    return;
}

template<class T>
T MinMaxHeap<T>::getMin()
{
    return heap[1];
}

template<class T>
T MinMaxHeap<T>::getMax()
{
    return (heap[2]>heap[3]?heap[2]:heap[3]);
}

template<class T>
void MinMaxHeap<T>::print()
{
    for(int i = 1;i<=size;i++)
    {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}
