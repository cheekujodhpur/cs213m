#ifndef MINMAXHEAP_H_
#define MINMAXHEAP_H_

template<class T>
class MinMaxHeap
{
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
        void deleteElems(pred predObject);
};

#endif //MINMAXHEAP_H_
