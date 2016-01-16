#include "list.hpp"

Node* insert(Node* head, int val, int pos)
{
    //the new node
    Node* the_new_node = new Node(val);
    
    //find the node we are going to replace
    Node* iter_ptr = head;

    //insert at HEAD
    if(pos==0)
    {
        the_new_node->setNext(head);
        return the_new_node;
    }
    else
    {
        for(int i = 0;i<pos-1;i++)
            iter_ptr = iter_ptr->getNext();

        //insertion procedure
        the_new_node->setNext(iter_ptr->getNext());
        iter_ptr->setNext(the_new_node);
        return head;
    }
}

Node* remove(Node* head, int pos)
{
    //find the node we are going to replace
    Node* iter_ptr = head;

    if(pos==0)
    {
        return head->getNext();
    }
    else 
    {
        for(int i = 0;i<pos-1;i++)
            iter_ptr = iter_ptr->getNext();

        //insertion procedure
        iter_ptr->setNext(iter_ptr->getNext()->getNext());
        return head;
    }
}

int size(Node* head)
{
    int i = 0;
    for(Node*iter_ptr=head;iter_ptr!=NULL;iter_ptr=iter_ptr->getNext())
        i++;
    return i;
}

Node* reverse(Node* head)
{
    //suppose there were only two elements
    if(size(head)<=2)
    {
        head->getNext()->setNext(head);
        head = head->getNext();
        return head;
    }
    else
    {
        //the recursion the man
        Node* the_new_head = reverse(head->getNext());
        head->getNext()->setNext(head);
        head->setNext(NULL);
        head = the_new_head;
        return head;
    }
}

int cycle_size(Node* head)
{
    /* Floyd's cycle finding algorithm
     * start with two pointers
     * increment the first by one, second by two
     * if they meet, cycle found
     * now traverse cycle once for length
     */

    int length = 0;
    Node *ptr1=head,*ptr2=head;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        ptr1 = ptr1->getNext();
        ptr2 = ptr2->getNext()->getNext();
        if(ptr1==ptr2)
        {
            do
            {
                ptr2=ptr2->getNext();
                length++;
            } while(ptr1!=ptr2);
            break;
        }
    }    
    return length;
}
