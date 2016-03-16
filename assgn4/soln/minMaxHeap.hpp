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
class Predicate
{
    public:
    virtual bool toDelete(T elem){};
};

template<class T>
class MinMaxHeap
{
    T heap[MAX_SIZE];
    int size;


    void BubbleUpMin(int i);
    void BubbleUpMax(int i);
    int min_child_grandchild(int i)
    {
        int result = i*2;
        if(i*2+1<=size)
        {
            if(heap[i*2+1]<heap[result])result=i*2+1;
        }
        if(i*4+3<=size)
        {
            if(heap[i*4+3]<heap[result])result=i*4+3;
            if(i*4+2<=size)if(heap[i*4+2]<heap[result])result=i*4+2;
            if(i*4+1<=size)if(heap[i*4+1]<heap[result])result=i*4+1;
            if(i*4+0<=size)if(heap[i*4+0]<heap[result])result=i*4+0;
        }
        return result;
    }
    int max_child_grandchild(int i)
    {
        int result = i*2;
        if(i*2+1<=size)
        {
            if(heap[i*2+1]>heap[result])result=i*2+1;
        }
        if(i*4+3<=size)
        {
            if(heap[i*4+3]>heap[result])result=i*4+3;
            if(i*4+2<=size)if(heap[i*4+2]>heap[result])result=i*4+2;
            if(i*4+1<=size)if(heap[i*4+1]>heap[result])result=i*4+1;
            if(i*4+0<=size)if(heap[i*4+0]>heap[result])result=i*4+0;
        }
        return result;
    }
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
        void deleteElems(Predicate<T> &predObject);
        void print();
};

template<class T>
void MinMaxHeap<T>::deleteElems(Predicate<T> &predObject)
{
    MinMaxHeap<int> *second = new MinMaxHeap<int>;
    for(int i = 1;i<=size;i++)
    {
        if(!predObject.toDelete(heap[i]))
            second->insert(heap[i]);
    }
    *this = *second;
}

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
    int m,i,last;
    T x;
    if(size==0)
        return;
    heap[0] = heap[1];
    x = heap[size];

    for(i = 1,last = size/2; i<=last;)
    {
        m = min_child_grandchild(i);
        if(x <= heap[m])        
            break;
        
        heap[i] = heap[m];

        if(m <= 2*i + 1)
        {
            i = m;
            break;
        }

        if(x > heap[m/2])
            swap(heap[m/2],x);

        i = m;
    }
    heap[i] = x;
    size--;
}

template<class T>
void MinMaxHeap<T>::deleteMax()
{
    int m,i,last;
    T x;
    if(size==0)
        return;
    else if(size==1)
    {
        heap[0]=heap[1];
        size--;
        return;
    }
    else if(size==2)
    {
        heap[0]=heap[2];
        size--;
        return;
    }
    heap[0] = (heap[2]>heap[3]?heap[2]:heap[3]);
    int start = (heap[2]>heap[3]?2:3);
    x = heap[size];

    for(i = start,last = size/2; i<=last;)
    {
        m = max_child_grandchild(i);
        if(x >= heap[m])        
            break;
        
        heap[i] = heap[m];

        if(m <= 2*i + 1)
        {
            i = m;
            break;
        }

        if(x < heap[m/2])
            swap(heap[m/2],x);

        i = m;
    }
    heap[i] = x;
    size--;
}

template<class T>
T MinMaxHeap<T>::getMin()
{
    return heap[1];
}

template<class T>
T MinMaxHeap<T>::getMax()
{
    if(size==1)
        return heap[1];
    else if(size==2)
        return heap[2];
    else
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
