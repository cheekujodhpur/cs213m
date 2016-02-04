#include "queue_vector.hpp"
#include <algorithm>

template <class T>
queue_vector<T>::queue_vector()
{
    v = vector<T>();
}

template <class T>
queue_vector<T>::queue_vector(const queue_vector &to_copy_to)
{
    v = to_copy_to.v;
}

template <class T>
queue_vector<T>::~queue_vector()
{
    v.~vector();
}

template <class T>
void queue_vector<T>::push_back(T n)
{
    v.push_back(n);
}

template <class T>
int queue_vector<T>::front(T *top_element)
{
    if(v.size())
    {
        *top_element = v.front();
        return 1;
    }
    else
        return -1;
}

template <class T>
void queue_vector<T>::pop_front()
{
    if(v.size())
    {
        v.erase(v.begin());
    }
}

template <class T>
int queue_vector<T>::size()
{
    return v.size();
} 
