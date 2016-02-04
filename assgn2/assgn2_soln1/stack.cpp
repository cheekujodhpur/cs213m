#include "stack.hpp"

template <class T>
stack<T>::stack()
{
    //empty stack
    head=0;
}

template <class T>
stack<T>::stack(const stack<T> &to_copy_to)
{
    head = to_copy_to.head;
}

template <class T>
void stack<T>::operator=(const stack<T> &rhs)
{
    head = rhs.head;
}

template <class T>
stack<T>::~stack()
{
    delete head;
}

template <class T>
void stack<T>::push(T n)
{
    struct stack_node *new_node = new struct stack_node;
    new_node->element = new T;
    *(new_node->element) = n;
    
    new_node->next=head;
    head = new_node;
}

template <class T>
int stack<T>::top(T* head_element)
{
    if(head==0)
        return -1;
    else
    {
        *head_element=*(head->element);
        return 1;
    }
}

template <class T>
void stack<T>::pop()
{
   if(head!=0)
   {
       head=head->next;
   } 
}

template <class T>
int stack<T>::size()
{
    int count = 0;
    stack_node* iter=head;
    while(iter!=0)
    {
        count++;
        iter = iter->next;
    }
    return count;
}
