#include "queue_list.hpp"

template <class T>
queue_list<T>::queue_list()
{
    q = list<T>();
}

template <class T>
queue_list<T>::queue_list(const queue_list &to_copy_to)
{
    q = to_copy_to.q;
}

template <class T>
queue_list<T>::~queue_list()
{
    q.~list();
}

template <class T>
void queue_list<T>::push_back(T n)
{
    q.push_back(n);
}

template <class T>
int queue_list<T>::front(T *top_element)
{
    if(q.size())
    {
        *top_element = q.front();
        return 1;
    }
    else
        return -1;
}

template <class T>
void queue_list<T>::pop_front()
{
    q.pop_front();
}

template <class T>
int queue_list<T>::size()
{
    return q.size();
} 
